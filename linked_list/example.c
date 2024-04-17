#include <stdio.h>
#include "hj_list.h"

int main() {
	struct hj_list lst;
	hj_list_init(&lst);

	int arr[] = {1, 2,3};
	for(int i = 0; i < 3; i++)
		hj_list_push_back(&lst, &arr[i]);
	int a = 0;
	hj_list_push_front(&lst, &a);

	struct hj_node *curr = lst.front;
	while(curr) {
		printf("%d ", *(int*)curr->data);
		curr = curr->next;
	}
	printf("\n");
	
	curr = lst.back;
	while(curr) {
		printf("%d ", *(int*)curr->data);
		curr = curr->prev;
	}
	printf("\n");

	void* ret = hj_list_pop_front(&lst);
	printf("Popped: %d\n", *(int*)ret);
	ret = hj_list_pop_back(&lst);
	printf("Popped: %d\n", *(int*)ret);

	curr = lst.front;
	while(curr) {
		printf("%d ", *(int*)curr->data);
		curr = curr->next;
	}
	printf("\n");

	hj_list_clear(&lst);
	curr = lst.front;
	while(curr) {
		printf("%d ", *(int*)curr->data);
		curr = curr->next;
	}
	printf("Size: %lu\n", lst.size);


	printf("Success!\n");
}