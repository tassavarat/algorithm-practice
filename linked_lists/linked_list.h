#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct ListNode - singly linked list for leetcode
 * @val: node value
 * @next: pointer to next node
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

/**
 * struct list_integer_s - singly linked list codesignal
 * @value: node value
 * @next: pointer to next node
 */
typedef struct list_integer_s {
	int value;
	struct list_integer_s *next;
} list_integer;

/* llist_shared */
struct ListNode *arr_to_llist(char *vals[], size_t size);
struct ListNode *find_node(struct ListNode *node, int val);
void print_node_vals(struct ListNode *node);
void free_llist(struct ListNode *node);

#endif /* LINKED_LIST_H */
