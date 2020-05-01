#ifndef TREES_H
#define TREES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct tree_integer - binary tree node
 *
 * @value: integer stored in node
 * @left: pointer to left child node
 * @right: pointer to right child node
 */
typedef struct tree_integer {
	int value;
	struct tree_integer *left;
	struct tree_integer *right;
} tree_integer;


/**
 * struct stack - doubly linked list
 * @sum: current sum
 * @node: pointer to binary tree node
 * @prev: pointer to previous node
 * @next: pointer to next node
 */
struct stack {
	int sum;
	struct tree_integer *node;
	struct stack *prev;
	struct stack *next;
};

void print_t(struct tree_integer *tree);
bool has_path_with_given_sum(struct tree_integer *t, int s);
bool is_tree_symmetric(struct tree_integer *t);
int kth_smallest_in_bst(struct tree_integer *t, int k);

#endif /* TREES_H */
