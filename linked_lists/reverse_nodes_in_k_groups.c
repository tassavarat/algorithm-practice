int group_left(list_integer **check, int k)
{
	int i;

	printf("group_left called\n");
	for (i = 1; i < k && *check; ++i)
	{
		printf("check->value: %d\n", (*check)->value);
		*check = (*check)->next;
	}
	if (*check)
		printf("check->value: %d\n", (*check)->value);
	if (!*check)
		return (0);
	return (1);
}

list_integer *reverseNodesInKGroups(list_integer *l, int k)
{
	int i;
	list_integer *cur, *check, *end, *tmp_end, *tmp, *rev;

	i = 0;
	cur = check = end = tmp = rev = l;
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
				end->next = tmp_end;
				printf("tmp_end->value: %d\n", tmp_end->value);
				break;
			}
			if (i != 0)
			{
				printf("end->value: %d\n", end->value);
				end->next = check;
				end = tmp_end;
				printf("check->value: %d\n", check->value);
			}
			check = check->next;
			tmp_end = check;
			if (tmp_end)
				printf("tmp_end->value: %d\n", tmp_end->value);
		}
		cur = cur->next;
		++i;
		printf("####################\n");
	}
	return (NULL);
}
