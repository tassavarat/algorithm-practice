#include "trees.h"

bool has_path_with_given_sum(struct tree_integer *t, int s)
{
	if (!t)
		return (false);
	s -= t->value;
	if (!t->left && !t->right)
		return (s == 0);
	return (has_path_with_given_sum(t->left, s) || has_path_with_given_sum(t->right, s));
}
