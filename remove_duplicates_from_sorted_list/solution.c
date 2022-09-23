#include "../leetcode.h"

/**
 * deleteDuplicates() - frees duplicate linked list values
 * @head: pointer to head head of linked list
 *
 * Return: head of linked list
 */
struct ListNode *deleteDuplicates(struct ListNode *head)
{
	if (head == NULL)
		return head;

	struct ListNode *cur = head, *next = cur->next;

	while (next != NULL) {
		if (cur->val == next->val) {
			cur->next = cur->next->next;
			free(next);
			next = cur->next;
		} else {
			cur = cur->next;
			next = next->next;
		}
	}
	return head;
}

/**
 * free_list() - frees given linked list
 * @head: pointer to linked list to free
 */
void free_list(struct ListNode *head)
{
	struct ListNode *tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * print_list() - print val members of linked list
 * @head: head of linked list
 */
void print_list(struct ListNode *head)
{
	struct ListNode *cur;

	for (cur = head; cur != NULL; cur = cur->next) {
		if (cur == head)
			printf("%d", cur->val);
		else 
			printf("->%d", cur->val);
	}
	putchar('\n');
}

/**
 * print_dedup_free() - wrapper to call print_list(), deleteDuplicates(), and free_list()
 * @head: pointer to head of linked list
 */
void print_dedup_free(struct ListNode *head)
{
	puts("Given linked list:");
	print_list(head);
	deleteDuplicates(head);
	puts("Deduped linked list:");
	print_list(head);
	free_list(head);
}

/**
 * create_list_node() - create linked list node
 * @n: value to assign to val member
 *
 * Return: created node, NULL if malloc fails
 */
struct ListNode *create_list_node(int n) {
	struct ListNode *node = malloc(sizeof(struct ListNode));
	if (node == NULL)
		return NULL;

	node->val = n;
	node->next = NULL;
	return node;
}

/**
 * arr_to_list() - convert array to linked list
 * @arr: array to convert
 * @size: size of array
 *
 * Return: pointer to head of linked list, NULL if create_list_node() failed
 */
struct ListNode *arr_to_list(int *arr, size_t size)
{
	int i;
	struct ListNode *head = NULL, *new, *cur;

	for (i = 0; i < size; ++i) {
		new = create_list_node(arr[i]);
		if (new == NULL)
			return NULL;

		if (head == NULL)
			cur = head = new;
		cur->next = new;
		cur = new;
	}
	return head;
}

int main()
{
	int arr1[] = {1, 1, 2};
	int arr2[] = {1, 1, 2, 3, 3};
	int arr3[] = {1, 1, 1};
	struct ListNode *head;

	head = arr_to_list(arr1, sizeof(arr1) / sizeof(*arr1));
	if (head == NULL)
		return 1;
	print_dedup_free(head);

	head = arr_to_list(arr2, sizeof(arr2) / sizeof(*arr2));
	if (head == NULL)
		return 1;
	print_dedup_free(head);

	head = arr_to_list(arr3, sizeof(arr3) / sizeof(*arr3));
	if (head == NULL)
		return 1;
	print_dedup_free(head);

	return 0;
}
