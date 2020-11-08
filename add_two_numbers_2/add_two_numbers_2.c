#include "../leetcode.h"

/**
 * stack_pop - pop node from stack
 * @node: stack to pop
 *
 * Return: node value in popped stack
 */
int stack_pop(struct list_stack **node)
{
	struct list_stack *tmp = *node;
	int val;

	*node = (*node)->next;
	val = tmp->node->val;
	free(tmp);
	return val;
}

/**
 * stack_push - create stack of pointers to ListNode
 * @stack: stack to push to
 * @node: node to push to stack
 *
 * Return: head node of stack, NULL on error
 */
struct list_stack *stack_push(struct list_stack *stack, struct ListNode *node)
{
	struct list_stack *new;

	new = malloc(sizeof(*new));
	if (!new)
		return NULL;
	new->node = node;
	if (!stack)
		new->next = NULL;
	else
		new->next = stack;
	return new;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *lsum, *cur_node, *tmp;
	struct list_stack *stack1 = NULL, *stack2 = NULL;
	int sum;

	for (cur_node = l1; cur_node; cur_node = cur_node->next) {
		stack1 = stack_push(stack1, cur_node);
		if (!stack1)
			return NULL;
	}
	for (cur_node = l2; cur_node; cur_node = cur_node->next) {
		stack2 = stack_push(stack2, cur_node);
		if (!stack2)
			return NULL;
	}
	tmp = NULL;
	sum = 0;
	while (stack1 || stack2 || sum != 0) {
		lsum = malloc(sizeof(*lsum));
		if (!lsum)
			return NULL;
		if (stack1)
			sum += stack_pop(&stack1);
		if (stack2)
			sum += stack_pop(&stack2);
		lsum->val = sum % 10, lsum->next = tmp;
		tmp = lsum;
		sum /= 10;
	}
	return lsum;
}

/**
 * free_list - free given list
 * @node: head node of list to free
 */
void free_list(struct ListNode *node)
{
	struct ListNode *tmp;

	while (node) {
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

/**
 * arrtol - create linked list storing same data as given array
 * @a: array to copy data
 * @l: length of array
 *
 * Return: created list, NULL on error
 */
struct ListNode *arrtol(int *a, size_t l)
{
	struct ListNode *cur, *tmp, *list;
	size_t i;

	for (i = 0; i < l; ++i) {
		cur = malloc(sizeof(*cur));
		if (!cur)
			return NULL;
		if (i == 0)
			tmp = list = cur;
		tmp = tmp->next = cur;
		cur->val = a[i], cur->next = NULL;
	}
	return list;
}

int main()
{
	struct ListNode *l1, *l2, *lsum, *cur;
	int a1[] = {7, 2, 4, 3};
	int a2[] = {5, 6, 4};
	/* int a1[] = {5}; */
	/* int a2[] = {5}; */

	l1 = arrtol(a1, sizeof(a1) / sizeof(*a1));
	if (!l1)
		return 1;
	l2 = arrtol(a2, sizeof(a2) / sizeof(*a2));
	if (!l2)
		return 1;
	cur = lsum = addTwoNumbers(l1, l2);
	if (!lsum)
		return 1;
	while (cur) {
		printf("%i", cur->val);
		cur = cur->next;
		if (cur)
			printf(" -> ");
	}
	putchar('\n');
	free_list(l1);
	free_list(l2);
	free_list(lsum);
	return 0;
}
