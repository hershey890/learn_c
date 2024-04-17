#include <stdlib.h>
#include "hj_list.h"

typedef struct hj_list hj_list;

void hj_list_init(hj_list *lst) {
	lst->front = NULL;
	lst->back = NULL;
	lst->size = 0;
}

int hj_list_push_front(hj_list *lst, void *data) {
	struct hj_node* n = (struct hj_node*)malloc(sizeof(struct hj_node));
	if(!n)
		return -1;
	n->data = data;
	n->next = lst->front;
	n->prev = NULL;

	if(!lst->front) // if empty list
		lst->back = n;
	if(lst->front)
		lst->front->prev = n;
	lst->front = n;
	lst->size++;
	return 0;
}

int hj_list_push_back(hj_list *lst, void *data) {
	struct hj_node* n = (struct hj_node*)malloc(sizeof(struct hj_node));
	if(!n)
		return -1;
	n->data = data;
	n->next = NULL;
	n->prev = lst->front ? lst->back : NULL;

	if(!lst->front) // if empty list
		lst->front = n;
	else
		lst->back->next = n;
	lst->back = n;
	lst->size++;
	return 0;
}

void* hj_list_pop_front(hj_list *lst) {
	void *ret = NULL;
	if(lst->front) {
		lst->size--;
		ret = lst->front->data;
		if(lst->front == lst->back) {
			free(lst->front);
			lst->front = NULL;
			lst->back = NULL;
		} else {
			struct hj_node *next = lst->front->next;
			free(lst->front);
			lst->front = next;
			lst->front->prev = NULL;
		}
	}
	return ret;
}

void* hj_list_pop_back(hj_list *lst) {
	void *ret = NULL;
	if(lst->back) {
		lst->size--;
		ret = lst->back->data;
		if(lst->front == lst->back) {
			free(lst->back);
			lst->front = NULL;
			lst->back = NULL;
		} else {
			struct hj_node *prev = lst->back->prev;
			free(lst->back);
			lst->back = prev;
			lst->back->next = NULL;
		}
	}
	return ret;
}

void hj_list_clear(hj_list *lst) {
	while(hj_list_pop_front(lst));
}