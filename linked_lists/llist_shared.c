#include "linked_list.h"

/**
 * free_llist - free linked list nodes
 * @node: node to start freeing from
 */
void free_llist(struct ListNode *node)
{
	struct ListNode *tmp;

	while (node) {
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

/**
 * print_node_vals - print linked list node val member
 * @node: node to start printing from
 */
void print_node_vals(struct ListNode *node)
{
	puts("Linked list vals:");
	while (node) {
		printf("%i ", node->val);
		node = node->next;
	}
	putchar('\n');
}

/**
 * find_node - find node with specified value
 * @node: starting node to search from
 * @val: value to search for
 *
 * Return: node containing value or NULL if not found
 */
struct ListNode *find_node(struct ListNode *node, int val)
{
	while (node && node->val != val)
		node = node->next;
	return node;
}

/**
 * create_node - create and link nodes
 * @head: double pointer to head node
 * @tail: pointer to tail node
 * @val: value to store in node
 *
 * Return: pointer to created node or NULL on malloc fail
 */
struct ListNode *create_node(struct ListNode **head, struct ListNode *tail, char *val)
{
	struct ListNode *new;

	if (*val < '0' || *val > '9')
		return NULL;
	new = malloc(sizeof(*new));
	if (!new)
		return NULL;
	if (!*head)
		*head = new;
	else
		tail->next = new;
	new->val = atoi(val);
	new->next = NULL;
	return new;
}

/**
 * arr_to_llist - create linked list from an array
 * @vals: array of values for each list node
 * @size: size of array
 *
 * Return: head node of linked list or NULL on malloc fail
 */
struct ListNode *arr_to_llist(char *vals[], size_t size)
{
	size_t i;
	struct ListNode *head, *tail;

	head = NULL;
	for (i = 0; i < size; ++i) {
		tail = create_node(&head, tail, vals[i]);
		if (!tail)
			return NULL;
	}
	return head;
}
