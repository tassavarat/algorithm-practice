#include "trees.h"

/**
 * pop - free the head node of a queue
 * @head: double pointer to head node
 *
 * Return: pointer to vertex pointed to by queue node being freed
 */
struct TreeNode *pop(queue_t **head)
{
	queue_t *tmp;
	struct TreeNode *node;

	if (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		node = tmp->node;
		free(tmp);
	}
	return (node);
}

/**
 * push - push new node into a queue
 * @head: double pointer to head node of queue
 * @tail: pointer to tail node of queue
 * @v: pointer to node queue will point to
 *
 * Return: newly created node, NULL on failure
 */
queue_t *push(queue_t **head, queue_t *tail, struct TreeNode *node)
{
	queue_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
		tail->next = new;
	return (new);
}

/**
 * invertTree - invert a binary tree
 * @root: pointer root node of binary tree
 *
 * Return: pointer to root node of binary tree, NULL on malloc fail
 */
struct TreeNode *invertTree(struct TreeNode *root)
{
	struct TreeNode *cur_n, *tmp_n;
	queue_t *head_q, *tail_q;

	head_q = tail_q = NULL;
	cur_n = root;
	tail_q = push(&head_q, tail_q, cur_n);
	if (!tail_q)
		return NULL;
	while (head_q && cur_n) {
		cur_n = head_q->node;
		if (cur_n->left) {
			tail_q = push(&head_q, tail_q, cur_n->left);
			if (!tail_q)
				return NULL;
		}
		if (cur_n->right) {
			tail_q = push(&head_q, tail_q, cur_n->right);
			if (!tail_q)
				return NULL;
		}
		tmp_n = head_q->node->left;
		head_q->node->left = head_q->node->right;
		head_q->node->right = tmp_n;
		pop(&head_q);
	}
	return root;
}

int main()
{
	struct TreeNode *root;
	char *a[] = {"4", "2", "7", "1", "3", "6", "9"};
	size_t size = sizeof(a) / sizeof(*a);

	root = NULL;
	if (!create_tree(&root, a, 0, size))
		return 1;
	puts("Before");
	print_t_l(root);
	root = invertTree(root);
	puts("Inverted");
	print_t_l(root);
	free_tree_l(root);
	return 0;
}
