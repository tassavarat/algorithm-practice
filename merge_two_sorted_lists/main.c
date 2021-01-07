#include "../leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *tmp = NULL, *head;

	if (!l2) {
		return l1;
	}
	if (!l1) {
		return l2;
	}
	if (l1->val <= l2->val)
		head = l1;
	else
		head = l2;

	while (l1 && l2) {
		if (l1->val <= l2->val) {
			if (!tmp) {
				tmp = l1;
			} else {
				tmp->next = l1;
				tmp = l1;
			}
			l1 = l1->next;
			tmp->next = l2;
		} else {
			if (!tmp) {
				tmp = l2;
			} else {
				tmp->next = l2;
				tmp = l2;
			}
			l2 = l2->next;
			tmp->next = l1;
		}
	}
	return head;
}

struct ListNode *createnode(int val)
{
	struct ListNode *new;

	new = malloc(sizeof(*new));
	if (!new)
		return NULL;
	new->val = val;
	new->next = NULL;
	return new;
}

struct ListNode *arrtolist(int *arr, size_t size)
{
	size_t i;
	struct ListNode *head, *cur, *new;

	for (i = 0; i < size; ++i) {
		if (i == 0) {
			head = cur = createnode(arr[i]);
			if (!cur)
				return NULL;
		} else {
			new = createnode(arr[i]);
			if (!new)
				return NULL;
			cur->next = new;
			cur = cur->next;
		}
	}
	return head;
}

int main()
{
	struct ListNode *l1, *l2, *merged, *cur, *tmp;
	size_t i, size1, size2;
	int arr1[] = {1, 2, 4}, arr2[] = {1, 3, 4};
	/* int arr1[] = {5}, arr2[] = {1, 2, 4}; */

	size1 = sizeof(arr1) / sizeof(*arr1);
	size2 = sizeof(arr2) / sizeof(*arr2);
	printf("l1:");
	for (i = 0; i < size1; ++i)
		printf(" %i", arr1[i]);
	putchar('\n');
	printf("l2:");
	for (i = 0; i < size2; ++i)
		printf(" %i", arr2[i]);
	putchar('\n');

	l1 = arrtolist(arr1, size1);
	if (!l1)
		return 1;
	l2 = arrtolist(arr2, size2);
	if (!l2)
		return 1;

	merged = mergeTwoLists(l1, l2);
	if (!merged || (merged != l1 && merged != l2))
		return 1;
	printf("merged: ");
	cur = merged;
	while (cur) {
		tmp = cur;
		cur = cur->next;
		printf(" %i", tmp->val);
		free(tmp);
	}
	putchar('\n');
}
