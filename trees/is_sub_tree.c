#include "trees.h"

/**
 * check_subtree - checks t1 and t2 to determine if t2 is subtree of t1
 * @t1: tree being checked for subtree
 * @t2: subtree
 *
 * Return: true if subtree contained in t1, otherwise false
 */
bool check_subtree(tree_integer *t1, tree_integer *t2)
{
	if (!t2)
		return t1 ? 0 : 1;
	if (!t1)
		return 0;
	if (t1->value != t2->value)
		return 0;
	if (!check_subtree(t1->left, t2->left) ||
			!check_subtree(t1->right, t2->right))
		return 0;
	return 1;
}

/**
 * is_subtree - traverses t1 and calls check_subtree as needed
 * @t1: tree being checked for subtree
 * @t2: subtree
 *
 * Return: true if subtree contained in t1, otherwise false
 */
bool is_subtree(tree_integer *t1, tree_integer *t2)
{
	if (!t1 && !t2)
		return 1;
	if (!t1)
		return 0;
	if (check_subtree(t1, t2))
		return 1;
	if (is_subtree(t1->left, t2) || is_subtree(t1->right, t2))
		return 1;
	return 0;
}

/**
 * main - entry point
 *
 * Return: always 0
 */
int main()
{
	tree_integer *t1, *t2;

	t1 = create_node(5);
	t1->left = create_node(10);
	t1->right = create_node(7);
	t1->left->left = create_node(4);
	t1->left->right = create_node(6);
	t1->left->left->left = create_node(1);
	t1->left->left->right = create_node(2);
	t1->left->right->right = create_node(-1);
	print_t(t1);
	t2 = create_node(10);
	t2->left = create_node(4);
	t2->right = create_node(6);
	t2->left->left = create_node(1);
	t2->left->right = create_node(2);
	t2->right->right = create_node(-1);
	print_t(t2);
	if (is_subtree(t1, t2))
		puts("t2 is a subtree of t1");
	else
		puts("t2 is not a subtree of t1");
	free_tree(t1);
	free_tree(t2);
	return 0;
}
