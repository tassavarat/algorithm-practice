#include "trees.h"

int inorder(struct TreeNode *node, int *k)
{
	int n;

	if (!node)
		return 0;
	n = inorder(node->left, k);
	if (!*k)
		return n;
	if (!--*k)
		return node->val;
	return inorder(node->right, k);
}

int kthSmallest(struct TreeNode *root, int k)
{
	return inorder(root, &k);
}

void call_validation(char *a[], size_t size, int k)
{
	struct TreeNode *root;

	root = NULL;
	create_tree(&root, a, 0, size);
	print_t_l(root);
	printf("%ith smallest: %i\n", k, kthSmallest(root, k));
	free_tree_l(root);
}

int main()
{
	char *a[] = {"3", "1", "4", "", "2"};
	char *b[] = {"5", "3", "6", "2", "4", "", "", "1"};
	char *c[] = {"1", "", "2"};
	char *d[] = {"1"};

	call_validation(a, sizeof(a) / sizeof(*a), 1);
	call_validation(b, sizeof(b) / sizeof(*b), 3);
	call_validation(c, sizeof(c) / sizeof(*c), 2);
	call_validation(d, sizeof(d) / sizeof(*d), 1);
	return 0;
}
