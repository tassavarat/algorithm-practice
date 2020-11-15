#include "../leetcode.h"

struct Node *connect(struct Node *root)
{
	if (!root)
		return NULL;

	struct Node *level, *cur;
	for (level = root; level->left; level = level->left) {
		for (cur = level; cur; cur = cur->next) {
			cur->left->next = cur->right;
			if (cur->next)
				cur->right->next = cur->next->left;
		}
	}
	return root;
}

/**
 * free_tree - frees binary tree
 * @tree: root node of tree to free
 */

void free_tree(struct Node *tree)
{
	if (!tree)
		return;
	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
}

/**
 * create_node- creates binary tree node
 * @value: value to store
 *
 * Return: newly created node, NULL on failure
 */
struct Node *create_node(char *value)
{
	struct Node *new;

	if (*value < 48 || *value > 57)
		return NULL;
	new = malloc(sizeof(*new));
	if (!new)
		return NULL;
	new->val= atoi(value);
	new->left = NULL;
	new->right = NULL;
	return new;
}

/**
 * create_tree - create binary tree from an array
 * @node: double pointer to root node
 * @a: array of node values
 * @size: size of array
 * @i: current array index
 *
 * Return: root node on success, NULL on failure
 */
struct Node *create_tree(struct Node **node, char *a[], size_t size, size_t i)
{
	if (i < size) {
		*node = create_node(a[i]);
		if (!*node)
			return NULL;
		create_tree(&(*node)->left, a, size, 2 * i + 1);
		create_tree(&(*node)->right, a, size, 2 * i + 2);
	}
	return *node;
}

int main()
{
	char *a[] = {"1", "2", "3", "4", "5", "6", "7"};
	struct Node *root = NULL;

	printf("%lu\n", sizeof(a) / sizeof(*a));
	root = create_tree(&root, a, sizeof(a) / sizeof(*a), 0);
	if (!root)
		return 1;
	free_tree(root);
	return 0;
}
