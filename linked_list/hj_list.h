/**
 * @brief Doubly Linked List
 * 
 * Holds a ptr to whatever value is inserted into the list, so if the object is destroyed (e.x. goes out of scope)
 * a copy of it allocated on the heap should be inserted into the list.
 */
#ifndef HJ_LIST_H
#define HJ_LIST_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct hj_node {
	void *data;
	struct hj_node *next;
	struct hj_node *prev;
};

struct hj_list {
	struct hj_node *front;
	struct hj_node *back;
	size_t size;
};

void hj_list_init(struct hj_list *lst);
int hj_list_push_front(struct hj_list *lst, void *data);
int hj_list_push_back(struct hj_list *lst, void *data);
void* hj_list_pop_front(struct hj_list *lst);
void* hj_list_pop_back(struct hj_list *lst);
void hj_list_clear(struct hj_list *lst);


#ifdef __cplusplus
}
#endif
#endif /* HJ_LIST_H */