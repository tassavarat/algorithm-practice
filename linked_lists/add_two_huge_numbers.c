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
 * is_list_palindrome - Determines whether list is a palindrome
 * @l: Pointer to head of list
 *
 * Return: true if list is palindrome, otherwise false
 */
list_integer *reverse_list(list_integer *head)
{
    list_integer *rev, *cur, *tmp;

    rev = NULL;
    cur = tmp = head;
    while (cur)
    {
        tmp = tmp->next;
        cur->next = rev;
        rev = cur;
        cur = tmp;
    }
    return (rev);
}

/**
 * add_two_huge_numbers - Add numbers between two linked lists together
 * @a: Pointer to head of first linked list
 * @b: Pointer to head of second linked list
 *
 * Result is stored in a newly created linked list
 * Return: Pointer to head of newly created linked list
 */
list_integer *add_two_huge_numbers(list_integer *a, list_integer *b)
{
    list_integer *rev_a, *rev_b, *cur_a, *cur_b, *c, *cur;
    int sum;

    rev_a = reverse_list(a);
    rev_b = reverse_list(b);
    cur_a = rev_a;
    cur_b = rev_b;
    c = NULL;
    sum = 0;
    while (cur_a || cur_b || sum / 10000)
    {
        if (cur_a && cur_b)
        {
            sum = cur_a->value + cur_b->value + sum / 10000;
	    cur_a = cur_a->next;
	    cur_b = cur_b->next;
        }
        else if (cur_a)
        {
            sum = cur_a->value + sum / 10000;
	    cur_a = cur_a->next;
        }
        else if (cur_b)
        {
            sum = cur_b->value + sum / 10000;
	    cur_b = cur_b->next;
        }
        else
        {
            cur = append_node(cur, sum / 10000);
            return (reverse_list(c));
        }
        if (!c)
            c = cur = append_node(NULL, sum % 10000);
        else
            cur = append_node(cur, sum % 10000);
    }
    return (reverse_list(c));
}
