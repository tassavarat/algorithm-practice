#ifndef LEETCODE_H
#define LEETCODE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * list_stack - stack of pointers to ListNode
 *
 * @node: pointer to ListNode
 * @next: pointer to next stack node
 */
struct list_stack {
	struct ListNode *node;
	struct list_stack *next;
};

struct ListNode {
	int val;
	struct ListNode *next;
};

#endif /* LEETCODE_H */
