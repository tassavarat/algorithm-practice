/**
 * reverse_list - Reverses linked list
 * @l: Pointer to head of linked list
 *
 * Return: Pointer to head reversed list
 */
list_integer *reverse_list(list_integer *l)
{
    list_integer *tmp, *cur, *rev;

    tmp = cur = l;
    rev = NULL;
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
 * is_list_palindrome - Determines whether list is a palindrome
 * @l: Pointer to head of list
 *
 * Return: true if list is palindrome, otherwise false
 */
bool is_list_palindrome(list_integer *l)
{
    list_integer *slow, *fast, *rev, *cur;

    slow = fast = cur = l;
    if (l)
    {
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        rev = slow = reverse_list(slow);
        while (rev)
        {
            if (cur->value != rev->value)
                return (false);
            cur = cur->next;
            rev = rev->next;
        }
        reverse_list(slow);
    }
    return (true);
}
