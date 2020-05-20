#include "trees.h"

static int height = 1;

int _print_t_l(struct TreeNode *tree, int is_left, int offset, int depth,
		char s[20][255])
{
	char b[20];
	int left, right, i, width = 5;

	if (!tree)
		return 0;
	sprintf(b, "(%03d)", tree->val);
	++height;
	left  = _print_t_l(tree->left,  1, offset,                depth + 1, s);
	right = _print_t_l(tree->right, 0, offset + left + width, depth + 1, s);
#ifdef COMPACT
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left) {
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	} else if (depth && !is_left) {
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
#else
	for (i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];
	if (depth && is_left) {
		for (i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i] = '-';
		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset + left + width + right + width / 2]
			= '+';
	} else if (depth && !is_left) {
		for (i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';
		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}
#endif
	return left + width + right;
}

void print_t_l(struct TreeNode *tree)
{
	char s[20][255];
	int i;

	for (i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");
	height = 1;
	_print_t_l(tree, 0, 0, 0, s);
	for (i = 0; i < height; i++)
		printf("%s\n", s[i]);
	if (height % 2)
		putchar('\n');
}

int _print_t(struct tree_integer *tree, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int left, right, i, width = 5;

	if (!tree)
		return 0;
	sprintf(b, "(%03d)", tree->value);
	left  = _print_t(tree->left,  1, offset,                depth + 1, s);
	right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);
#ifdef COMPACT
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left) {
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	} else if (depth && !is_left) {
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
#else
	for (i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];
	if (depth && is_left) {
		for (i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i] = '-';
		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset + left + width + right + width / 2] =
			'+';
	} else if (depth && !is_left) {
		for (i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';
		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}
#endif
	return left + width + right;
}

/**
 * print_t - print tree
 */
void print_t(struct tree_integer *tree)
{
	char s[20][255];
	int i;

	for (i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");

	_print_t(tree, 0, 0, 0, s);

	for (i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}

/**
 * create_tree - create binary tree from an array
 * @node: double pointer to root node
 * @a: array of node values
 * @i: current array index
 * @size: size of array
 *
 * Return: root node on success, NULL on failure
 */
struct TreeNode *create_tree(struct TreeNode **node, char *a[], size_t i,
		size_t size)
{
	if (i < size) {
		*node = create_node_l(a[i]);
		if (!*node)
			return NULL;
		create_tree(&(*node)->left, a, 2 * i + 1, size);
		create_tree(&(*node)->right, a, 2 * i + 2, size);
	}
	return *node;
}

/**
 * free_tree_l - frees binary tree for LeetCode
 * @tree: root node of tree to free
 */
void free_tree_l(struct TreeNode *tree)
{
	if (!tree)
		return;
	free_tree_l(tree->left);
	free_tree_l(tree->right);
	free(tree);
}

/**
 * free_tree - frees binary tree for CodeSignal
 * @tree: root node of tree to free
 */
void free_tree(tree_integer *tree)
{
	if (!tree)
		return;
	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
}

/**
 * create_node_l - creates binary tree node for LeetCode
 * @value: value to store
 *
 * Return: newly created node, NULL on failure
 */
struct TreeNode *create_node_l(char *value)
{
	struct TreeNode *new;

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
 * create_node - creates binary tree node for CodeSignal
 * @value: int value to store
 *
 * Return: newly created node, NULL on failure
 */
tree_integer *create_node(int value)
{
	tree_integer *new = malloc(sizeof(*new));

	if (!new)
		return NULL;
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return new;
}
