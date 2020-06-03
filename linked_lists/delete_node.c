#include "linked_list.h"

void deleteNode(struct ListNode *node)
{
	struct ListNode *tmp;

	if (node->next) {
		node->val = node->next->val;
		tmp = node->next;
		node->next = node->next->next;
		free(tmp);
	}
}

int main()
{
	char *vals[] = {"4", "5", "1", "9"};
	size_t size = sizeof(vals) / sizeof(*vals);
	struct ListNode *head, *node;

	head = arr_to_llist(vals, size);
	if (!head)
		return 1;
	node = find_node(head, 5);
	if (!node)
		return 1;
	deleteNode(node);
	print_node_vals(head);
	free_llist(head);
	return 0;
}
