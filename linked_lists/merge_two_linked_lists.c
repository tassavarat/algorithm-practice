/**
 * append_node - Creates and links new node to end of linked list
 * @head: Pointer to node in linked list
 * @value: Value to set to new node
 *
 * Return: Pointer to newly created node
 */
list_integer *append_node(list_integer *head, int value)
{
	list_integer *cur, *new;

	cur = head;
	new = malloc(sizeof(list_integer));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	return (new);
}

/**
 * merge_two_linked_lists - Merges two linked lists in ascending order
 * @l1: First linked list
 * @l2: Second linked list
 *
 * Return: Newly created merged linked list
 */
list_integer *merge_two_linked_lists(list_integer *l1, list_integer *l2)
{
	list_integer *cur_l1, *cur_l2, *cur_l3, *l3;
	int val;

	cur_l1 = l1;
	cur_l2 = l2;
	l3 = NULL;
	while (cur_l1 || cur_l2)
	{
		if (cur_l1 && cur_l2)
		{
			if (cur_l1->value < cur_l2->value)
			{
				val = cur_l1->value;
				cur_l1 = cur_l1->next;
			}
			else
			{
				val = cur_l2->value;
				cur_l2 = cur_l2->next;
			}
		}
		else if (cur_l1)
		{
			val = cur_l1->value;
			cur_l1 = cur_l1->next;
		}
		else
		{
			val = cur_l2->value;
			cur_l2 = cur_l2->next;
		}
		if (!l3)
			l3 = cur_l3 = append_node(NULL, val);
		else
			cur_l3 = append_node(cur_l3, val);
	}
	return (l3);
}
