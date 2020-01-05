#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct list_integer_s - Singly linked list
 * @value: Integer
 * @next: Points to next node
 */
typedef struct list_integer_s
{
	int value;
	struct list_integer_s *next;
} list_integer;

/* remove_k_from_list */
list_integer *remove_k_from_list(list_integer *l, int k);

/* is_list_palindrome */
bool is_list_palindrome(list_integer *l);
list_integer *reverse_list(list_integer *l);

/* add_two_huge_numbers */
list_integer *add_two_huge_numbers(list_integer *a, list_integer *b);

/* merge_two_linked_lists */
list_integer *merge_two_linked_lists(list_integer *l1, list_integer *l2);
list_integer *append_node(list_integer *head, int value);

/* reverse_nodes_in_k_groups */
list_integer *reverse_nodes_in_k_groups(list_integer *l, int k);
int group_left(list_integer **check, int k);
void link_groups(int i, list_integer **end, list_integer **tmp_end,
	list_integer **check);
void reverse_list_g(list_integer **cur, list_integer **tmp, list_integer **rev,
	list_integer **head, int i, int k);

/* rearrange_last_n */
list_integer *rearrange_last_n(list_integer *l, int n);

#endif /* LINKED_LIST_H */
