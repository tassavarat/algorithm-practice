#include "trees.h"

/**
 * check_symmetry - recursive DFS for symmetry
 * @tl: pointer to tree's left node
 * @tr: pointer to tree's right node
 *
 * Return: true if tree is symmetric, otherwise false
 */
bool check_symmetry(struct tree_integer *tl, struct tree_integer *tr)
{
	if (!tl && !tr)
		return (true);
	if (!tl || !tr || tl->value != tr->value)
		return (false);
	return (check_symmetry(tl->left, tr->right) &&
			check_symmetry(tl->right, tr->left));
}

/**
 * is_tree_symmetric - calls check_symmetry and returns its result
 * @t: pointer to root node
 *
 * Return: true if tree is NULL or symmetric, otherwise false
 */
bool is_tree_symmetric(struct tree_integer *t)
{
	if (!t)
		return (true);
	return (check_symmetry(t->left, t->right));
}
