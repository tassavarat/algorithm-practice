/**
 * remove_k_from_list - Removes all nodes containing k from list
 * @l: Pointer to head node
 * @k: Value being removed
 *
 * Return: Pointer to head of updated list
 */
list_integer *remove_k_from_list(list_integer *l, int k)
{
	list_integer *cur, *tmp;

	cur = tmp = l;

	while (cur)
	{
		if (cur->value == k && cur != l)
		{
			tmp->next = cur->next;
			free(cur);
		}
		else
		{
			tmp = cur;
		}
		cur = tmp->next;
		if (tmp->value == k)
		{
			l = cur;
			free(tmp);
		}
	}
	return (l);
}
