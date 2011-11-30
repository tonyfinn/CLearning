#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

TreeNode* make_treenode(int value) {
	TreeNode* tnode;
	tnode = (TreeNode *) malloc(sizeof(TreeNode));
	tnode->left = NULL;
	tnode->right = NULL;
	tnode->value = value;

	return tnode;
}

TreeNode* add_value(TreeNode* node, int value) {
	if(node->value > value) {
		if(node->right != NULL) {
			add_value(node->right, value);
		} else {
			node->right = make_treenode(value);
		}
	} else if(node->value < value) {
		if(node->left != NULL) {
			add_value(node->left, value);
		} else {
			node->left = make_treenode(value);
		}
	}
}

bool contains_value(TreeNode* node, int value) {
	if(node->value == value) {
		return true;
	} else if(node->value < value) {
		if(node->left == NULL) {
			return false;
		} else {
			return contains_value(node->left, value);
		}
	} else {
		if(node->right == NULL) {
			return false;
		} else {
			return contains_value(node->right, value);
		}
	}
}


