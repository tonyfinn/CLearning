#include <stdio.h>
#include "btree.h"

int main(int argc, char** argv) {
	TreeNode* tnode = make_treenode(5);
	add_value(tnode, 7);
	add_value(tnode, 12);
	add_value(tnode, 8);
	add_value(tnode, 4);
	add_value(tnode, 5);
	add_value(tnode, 3);

	if(contains_value(tnode, 7))
		printf("Found 7\n");

	if(contains_value(tnode, 9))
		printf("Found 9: ERROR\n");

	if(contains_value(tnode, 2))
		printf("Found 2: ERROR\n");
}
