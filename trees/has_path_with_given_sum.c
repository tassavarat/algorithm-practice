#include "trees.h"

stack *push(stack *cur_s, tree_integer *cur)
{
        stack *new;

        new = malloc(sizeof(stack));
        new->node = cur;
        new->next = NULL;
        if (cur_s)
        {
                while (cur_s->next)
                        cur_s = cur_s->next;
                cur_s->next = new;
        }
        return (new);
}

stack *pop(stack *cur_s)
{
        stack *prev_s;

        prev_s = NULL;
	if (cur_s)
	{
		while (cur_s->next)
		{
			prev_s = cur_s;
			cur_s = cur_s->next;
		}
		free(cur_s);
		if (prev_s)
			prev_s->next = NULL;
	}
        return (prev_s);
}

bool has_path_with_given_sum(tree_integer *t, int s)
{
        int sum, prev_sum, jumped;
        tree_integer *cur, *prev;
        stack *cur_s;

	if (t)
	{
		sum = t->value;
		prev_sum = jumped = 0;
		cur = t;
		prev = NULL;
		cur_s = NULL;
		while (cur && (jumped == 0 || cur->left || cur->right))
		{
			printf("cur->value: %d\n", cur->value);
			printf("before sum: %d\n", sum);
			printf("prev_sum: %d\n", prev_sum);
			if (cur->left && cur->right)
			{
				// printf("cur->value: %d\n", cur->value);
				prev_sum += cur->value;
				jumped = 0;
				prev = cur->right;
				cur_s = push(cur_s, cur);
				cur = cur->left;
			}
			else if (cur->left)
			{
				if (!cur_s)
					prev_sum += cur->value;
				cur = cur->left;
			}
			else if (cur->right)
			{
				if (!cur_s)
					prev_sum += cur->value;
				cur = cur->right;
			}
			else
			{
				if (sum == s)
					return (true);
				if (cur_s)
					sum = prev_sum;
				jumped = 1;
				cur_s = pop(cur_s);
				if (!cur_s)
					cur = prev;
				printf("Jumped\n");
				printf("####\n");
			}
			if (cur)
				sum += cur->value;
			printf("after sum: %d\n", sum);
			printf("##########\n");
		}
		// printf("after loop cur->value: %d\n", cur->value);
		printf("after loop sum: %d\n", sum);
		if (sum == s)
			return (true);
	}
	return (false);
}
