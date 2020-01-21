#include "trees.h"

/**
 * kth_smallest_in_bst - Finds kth smallest element in BST
 * @t: Pointer to node
 * @k: Integer specifying which smallest element
 *
 * Return: Specified smallest element or -1 if t is NULL
 */
int kth_smallest_in_bst(struct tree_integer *t, int k)
{
	int i;
	struct tree_integer *cur;

	i = 1;
	while (t) {
		if (!t->left) {
			if (i++ == k)
				return (t->value);
			t = t->right;
		}
		else {
			cur = t->left;
			while (cur->right && cur->right != t)
				cur = cur->right;
			if (cur->right == t) {
				cur->right = NULL;
				if (i++ == k)
					return (t->value);
				t = t->right;
			}
			else {
				cur->right = t;
				t = t->left;
			}
		}
	}
	return (-1);
}
