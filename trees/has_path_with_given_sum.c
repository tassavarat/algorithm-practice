#include "trees.h"

/**
 * push - creates and appends nodes to linked list
 * @cur_s: pointer to list node
 * @cur: pointer to binary tree node
 *
 * Return: pointer to newly created node or NULL on failure
 */
struct stack *push(struct stack *cur_s, struct tree_integer *cur)
{
	struct stack *new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->node = cur;
	new->next = NULL;
	if (cur_s)
		cur_s->next = new;
	new->prev = cur_s;
	return (new);
}

/**
 * pop - removes last node in linked list
 * @cur_s: pointer to pointer of node
 *
 * Return: right child node of node being removed
 */
struct tree_integer *pop(struct stack **cur_s)
{
	struct tree_integer *tmp;
	struct stack *tmp_s;

	tmp = NULL;
	if (*cur_s) {
		tmp = (*cur_s)->node->right;
		tmp_s = *cur_s;
		*cur_s = (*cur_s)->prev;
		free(tmp_s);
		if (*cur_s)
			(*cur_s)->next = NULL;
	}
	return (tmp);
}

/**
 * has_path_with_given_sum - determines if path exists where sum matches
 * @t: pointer to root node of binary tree
 * @s: sum to check for
 *
 * Description:
 * sum is value of all nodes along path from root to leaf node
 * Return: true if sum found otherwise false
 */
bool has_path_with_given_sum(struct tree_integer *t, int s)
{
	bool hop;
	int sum;
	struct tree_integer *cur;
	struct stack *cur_s;

	if (t) {
		hop = false;
		sum = t->value;
		cur = t;
		cur_s = NULL;
		while (hop == false || cur) {
			if (cur->left && cur->right) {
				hop = false;
				cur_s = push(cur_s, cur);
				cur_s->sum = sum;
				cur = cur->left;
			}
			else if (cur->left) {
				cur = cur->left;
			}
			else if (cur->right) {
				cur = cur->right;
			}
			else {
				if (sum == s)
					return (true);
				hop = true;
				if (cur_s)
					sum = cur_s->sum;
				cur = pop(&cur_s);
			}
			if (cur)
				sum += cur->value;
		}
	}
	return (false);
}
