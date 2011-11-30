typedef struct ListItemS {
	int value;
	struct ListItemS* next;
} ListItem;

typedef struct {
	ListItem* first;
	int length;
} List;

List* make_list();

ListItem* make_item(int value);

ListItem* get_item(List* list, int index);

ListItem* add_item(List* list, int item);

void remove_item(List* list, int index);

void change_item(List* list, int index, int new_value);

ListItem* insert_before(List* list, int index, int value);
