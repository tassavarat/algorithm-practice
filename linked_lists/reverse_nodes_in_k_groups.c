#include "linked_list.h"

/**
 * reverse_list - Reverses a linked list
 * @cur: Iterates through linked list
 * @tmp: One node ahead of cur
 * @rev: Node cur will point to
 * @head: Head of linked list
 * @i: Current iteration
 * @k: Amount of nodes to reverse at a time
 */
void reverse_list(list_integer **cur, list_integer **tmp, list_integer **rev,
	list_integer **head, int i, int k)
{
	if (i == k)
	{
		*head = *rev;
		printf("reverse_list head->value: %d\n", (*head)->value);
	}
	*tmp = (*tmp)->next;
	if (i % k == 0)
	{
		*rev = *cur;
	}
	else
	{
		printf("cur->value: %d\n", (*cur)->value);
		(*cur)->next = *rev;
		printf("rev->value: %d\n", (*rev)->value);
		*rev = *cur;
	}
	*cur = *tmp;
}

/**
 * link_groups - Links the groups of nodes together
 * @i: Current iteration
 * @end: Node at the end of a group
 * @tmp_end: End node one iteration ahead
 * @check: Iterating node
 */
void link_groups(int i, list_integer **end, list_integer **tmp_end,
	list_integer **check)
{
	if (i != 0)
	{
		printf("link_groups end->value: %d\n", (*end)->value);
		(*end)->next = *check;
		*end = *tmp_end;
		printf("link_groups check->value: %d\n", (*check)->value);
	}
	*check = (*check)->next;
	if (*check)
		*tmp_end = *check;
	if (*tmp_end)
		printf("link_groups tmp_end->value: %d\n", (*tmp_end)->value);
}

/**
 * group_left - Checks if linked list contains enough nodes left to reverse
 * @check: Iterating node
 * @k: Amount of nodes to reverse at a time
 *
 * Return: 1 if enough nodes, otherwise 0
 */
int group_left(list_integer **check, int k)
{
	int i;

	for (i = 1; i < k && *check; ++i)
	{
		printf("group_left check->value: %d\n", (*check)->value);
		*check = (*check)->next;
	}
	if (*check)
		printf("group_left check->value: %d\n", (*check)->value);
	if (!*check)
		return (0);
	return (1);
}

/**
 * reverse_nodes_in_k_groups - Reverses nodes k groups at a time
 * @l: Pointer to head of linked list being reversed
 * @k: Amount of nodes to reverse at a time
 *
 * If there aren't enough nodes left the remaining nodes remain unaltered
 * Return: Pointer to head of reversed linked list
 */
list_integer *reverse_nodes_in_k_groups(list_integer *l, int k)
{
	int i, good_groups;
	list_integer *cur, *check, *end, *tmp_end, *head, *tmp, *rev;

	i = 0;
	good_groups = 1;
	cur = check = end = tmp = rev = l;
	head = NULL;
	if (k == 1)
		return (l);
	while (cur)
	{
		printf("i: %d\n", i);
		if (i % k == 0)
		{
			if (!group_left(&check, k))
			{
				printf("group_left returned false\n");
				printf("end->value: %d\n", end->value);
				if (!head)
					head = rev;
				end->next = tmp_end;
				printf("tmp_end->value: %d\n", tmp_end->value);
				good_groups = 0;
				break;
			}
			link_groups(i, &end, &tmp_end, &check);
		}
		reverse_list(&cur, &tmp, &rev, &head, i, k);
		++i;
		printf("####################\n");
	}
	if (good_groups)
		tmp_end->next = NULL;
	printf("return head->value: %d\n", head->value);
	return (head);
}
