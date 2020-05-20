#include "trees.h"

bool check_inorder(struct TreeNode *node, struct TreeNode **prev)
{
	if (!node)
		return true;
	if (!check_inorder(node->left, prev))
		return false;
	if (*prev && (*prev)->val >= node->val)
		return false;
	*prev = node;
	return check_inorder(node->right, prev);
}

bool isValidBST(struct TreeNode *root)
{
	struct TreeNode *prev = NULL;
	return check_inorder(root, &prev);
}

void call_validation(char *a[], size_t size)
{
	struct TreeNode *root;

	root = NULL;
	create_tree(&root, a, 0, size);
	print_t_l(root);
	printf("%s\n"
			"####################\n",
			isValidBST(root) ? "true" : "false");
	free_tree_l(root);
}

int main()
{
	char *a[] = {"2", "1", "3"};
	char *b[] = {"5", "1", "4", "", "", "3", "6"};
	char *c[] = {"1", "", "1"};
	char *d[] = {"0"};
	char *e[] = {"10", "5", "15", "", "", "6", "20"};

	call_validation(a, sizeof(a) / sizeof(*a));
	call_validation(b, sizeof(b) / sizeof(*b));
	call_validation(c, sizeof(c) / sizeof(*c));
	call_validation(d, sizeof(d) / sizeof(*d));
	call_validation(e, sizeof(e) / sizeof(*e));
	return 0;
}
