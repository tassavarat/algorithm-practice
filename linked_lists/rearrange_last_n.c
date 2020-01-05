#include "linked_list.h"

/**
 * rearrange_last_n - Moves the last n nodes to the beginning of linked list
 * @l: Pointer to the head node
 * @n: Amount of nodes from the end to move
 *
 * Return: Modified linked list
 */
list_integer *rearrange_last_n(list_integer *l, int n)
{
	int len, i;
	list_integer *head, *cur, *stop;

	len = 0;
	cur = l;
	if (n == 0)
		return (l);
	while (cur)
	{
		++len;
		cur = cur->next;
	}
	if (n == len)
		return (l);

	cur = l;
	for (i = 1; i < len; ++i)
	{
		if (i == len - n)
		{
			stop = cur;
			head = cur->next;
		}
		cur = cur->next;
	}
	cur->next = l;
	stop->next = NULL;
	return (head);
}
