#ifndef TREES_H
#define TREES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT -1
#define RIGHT 1

/**
 * struct tree_integer - binary tree node
 * @value: integer stored in node
 * @left: pointer to left child node
 * @right: pointer to right child node
 */
typedef struct tree_integer {
	int value;
	struct tree_integer *left;
	struct tree_integer *right;
} tree_integer;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
 * struct arr_integer - stores array and its size
 * @size: size of array
 * @arr: dynamic integer array
 */
typedef struct arr_integer {
	int size;
	int *arr;
} arr_integer;

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

tree_integer *create_node(int value);
void free_tree(tree_integer *tree);
void print_t(struct tree_integer *tree);
struct TreeNode *create_node_l(char *value);
void free_tree_l(struct TreeNode *tree);
struct TreeNode *create_tree(struct TreeNode **node, char *a[], size_t i,
		size_t size);
void print_t_l(struct TreeNode *tree);

#endif /* TREES_H */
