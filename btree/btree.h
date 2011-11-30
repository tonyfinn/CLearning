#include <stdbool.h>

typedef struct TreeNodeS {
	struct TreeNodeS* left;
	struct TreeNodeS* right;
	int value;
} TreeNode;

TreeNode* make_treenode(int value);

TreeNode* add_value(TreeNode* node, int value);

TreeNode* remove_node(TreeNode* node, TreeNode* removal);

bool contains_value(TreeNode* node, int value);
