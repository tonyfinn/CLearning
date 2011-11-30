#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List* make_list() {
	ListItem* first;
	List* list;
	list = (List *) malloc(sizeof(List));
	list->length = 0;
	list->first = NULL;
	return list;
}

ListItem* make_item(int value) {
	ListItem* item;
	item = (ListItem *) malloc(sizeof(ListItem));
	item->value = value;
	item->next = NULL;
	return item;
}

ListItem* add_item(List* list, int item) {
	ListItem* cur_item;
	ListItem* new_item = make_item(item);
	if(list->first == NULL) {
		list->first = new_item;
		list->length++;
		return list->first;
	} else {
		cur_item = list->first;
		while(cur_item != NULL) {
			if(cur_item->next == NULL) {
				cur_item->next = new_item;
				list->length++;
				return new_item;
			}
			cur_item = cur_item->next;
		}
	}
}

ListItem* get_item(List* list, int index) {
	ListItem* cur_item = list->first;
	int i = 0;
	while(i < index) {
		if(cur_item == NULL) {
			return NULL;
		}
		cur_item = cur_item->next;
		i++;
	}
	return cur_item;
}

ListItem* insert_before(List* list, int index, int value) {
	ListItem* previous_item;
	ListItem* target_item;
	ListItem* new_item;

	previous_item = get_item(list, index - 1);
	target_item = get_item(list, index);

	if(index == 0) { 
		new_item = make_item(value);
		new_item->next = target_item;
		list->first = new_item;
	} else if(previous_item != NULL) {
		new_item = make_item(value);
		new_item->next = target_item;
		previous_item->next = new_item;
	} else {
		new_item = add_item(list, value);
	}


	list->length++;
	return new_item;
}

void remove_item(List* list, int index) {
	ListItem* previous_item;
	ListItem* removal_item;
	ListItem* next_item;

	previous_item = get_item(list, index - 1);
	removal_item = get_item(list, index);
	next_item = get_item(list, index + 1);

	if(previous_item != NULL) {
		previous_item->next = next_item;
		list->length--;
		if(removal_item != NULL) {
			free(removal_item);
		}
	}
	
	printf("Removed\n");
}
