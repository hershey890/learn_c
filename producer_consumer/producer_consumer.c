/**
 * @file producer_consumer.c
 * @brief Implements a thread safe producer consumer buffer
 *
 * @param buffer_length Length of buffer to be created between the two threads
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdatomic.h>

/**
 * @brief Holds a dynamically allocated array implementing a circular buffer
 */
struct Buffer {
	pthread_mutex_t m;
	pthread_cond_t c;
	int* ptr;
	size_t idx;
	size_t size;
	size_t capacity;
	atomic_char msg_complete;
	//bool msg_complete;
	int (*create)(struct Buffer* buf, size_t capacity);
	void (*destroy)(struct Buffer* buf);
};

/**
 * @brief Initializes `Buffer`
 *
 * @param buf buffer to be initialized
 * @param capacity capacity of buffer to be initialized
 * @return 0 on success
 */
int create(struct Buffer* buffer, size_t capacity) {
	buffer->ptr = (int*)malloc(capacity*sizeof(int));
	if(buffer->ptr == NULL)
		return -1;
	if(pthread_mutex_init(&buffer->m, NULL))
		return -1;
	if(pthread_cond_init(&buffer->c, NULL))
		return -1;
	buffer->size = 0;
	buffer->capacity = capacity;
	buffer->msg_complete = 0;
	return 0;
}

/**
 * @brief Destroys `buf`
 *
 * @param buf `Buffer` to be destroyed
 */ 
void destroy(struct Buffer* buffer) {
	free(buffer->ptr);
	pthread_cond_destroy(&buffer->c);
	pthread_mutex_destroy(&buffer->m);
}

void producer(void* buffer) {
	/* Data stream to put in circular buffer */
	const size_t data_len = 128;
	int data_to_send[data_len];
	for(size_t i=0; i<data_len; i++)
		data_to_send[i] = i;

	struct Buffer* buf = (struct Buffer*)(buffer);
	for(size_t data_idx = 0; data_idx < data_len;) {
		pthread_mutex_lock(&buf->m);
		while(buf->size == buf->capacity) pthread_cond_wait(&buf->c, &buf->m);
		buf->ptr[buf->idx % buf->capacity] = data_to_send[data_idx++];
		buf->idx++;
		buf->size++;
		pthread_mutex_unlock(&buf->m);
		pthread_cond_broadcast(&buf->c);
	}	
	buf->msg_complete = 1;
	pthread_exit(0);
}

void consumer(void* buffer) {
	struct Buffer* buf = (struct Buffer*)(buffer);
	while(!buf->msg_complete) {
		pthread_mutex_lock(&buf->m);
		while(buf->size == 0) pthread_cond_wait(&buf->c, &buf->m);
		printf("C:%d, ", buf->ptr[buf->idx % buf->capacity]);
		buf->idx++;
		buf->size--;
		pthread_mutex_unlock(&buf->m);
		pthread_cond_broadcast(&buf->c);
	}	
	printf("\n");
	pthread_exit(0);
}

int main(int argc, char *argv[]) {
	/* Process Input Args */
	printf("Number of arguments: %d\n", argc);
	for(int i=0; i<argc; i++)
		printf("Argument: %s\n", argv[i]);
	
	if(argc < 2) {
		printf("Error: Pass buffer length as an argument\n");
		return 1;
	}
	if(argc > 2) {
		printf("Error: Invalid number of arguments\n");
		return 1;
	}
	int capacity = atoi(argv[1]);
	if(capacity < 1) {
		printf("Error: Buffer length must be positive");
		return 1;
	}

	/* Create Buffer */
	struct Buffer buf;
	buf.create = (void*)create;
	buf.destroy = (void*)destroy;
	if(buf.create(&buf, capacity)) {
		printf("Error: Buffer initialization failed\n");
		return 1;
	}

	/* Spawn and run threads */
	pthread_t pro_t;
	pthread_t con_t;
	pthread_create(&pro_t, NULL, (void*)producer, (void*)&buf);
	pthread_create(&con_t, NULL, (void*)consumer, (void*)&buf);

	/* Cleanup */
	if(pthread_join(con_t, NULL)) {
		printf("Error: Unable to join consumer thread\n");
		return 1;
	}
	if(pthread_join(pro_t, NULL)) {
		printf("Error: Unable to join producer thread\n");
		return 1;
	}
	buf.destroy(&buf);
	return 0;
}
