#include "list.h"
#include <stdio.h>

int main(int argc, char** argv) {
	List* my_list = make_list();

	add_item(my_list, 5);
	add_item(my_list, 6);
	add_item(my_list, 7);
	printf("%d %d %d\n", get_item(my_list, 0)->value, get_item(my_list, 1)->value, get_item(my_list, 2)->value);
	printf("Length: %d\n", my_list->length);

	/* Check removing item from a list. */
	remove_item(my_list, 1);
	printf("%d %d\n", get_item(my_list, 0)->value, get_item(my_list, 1)->value);
	printf("Length: %d\n", my_list->length);

	/* Check inserting midlist. */
	insert_before(my_list, 1, 12);
	printf("%d %d %d\n", get_item(my_list, 0)->value, get_item(my_list, 1)->value, get_item(my_list, 2)->value);
	printf("Length: %d\n", my_list->length);

	/* Check before inserts at beginning. */
	insert_before(my_list, 0, 17);
	printf("%d %d %d %d\n", get_item(my_list, 0)->value, get_item(my_list, 1)->value, get_item(my_list, 2)->value, get_item(my_list, 3)->value);
	printf("Length: %d\n", my_list->length);
}
