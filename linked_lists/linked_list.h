#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

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

list_integer *reverse_nodes_in_k_groups(list_integer *l, int k);
int group_left(list_integer **check, int k);
void link_groups(int i, list_integer **end, list_integer **tmp_end,
	list_integer **check);
void reverse_list(list_integer **cur, list_integer **tmp, list_integer **rev,
	list_integer **head, int i, int k);

#endif /* LINKED_LIST_H */
