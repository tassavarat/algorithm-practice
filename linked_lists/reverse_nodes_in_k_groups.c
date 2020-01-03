#include "linked_list.h"

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
