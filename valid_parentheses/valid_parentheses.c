#include "../leetcode.h"

struct stack {
	char c;
	struct stack *next;
};

char pop(struct stack **p)
{
	if (*p == NULL)
		return '\0';

	struct stack *tmp = *p;
	char c = tmp->c;

	(*p) = (*p)->next;
	free(tmp);
	return c;
}

void free_stack(struct stack *p)
{
	while (p != NULL)
		pop(&p);
}

struct stack *push(struct stack **p, char c)
{
	struct stack *new;

	if ((new = malloc(sizeof(*new))) == NULL)
		return NULL;

	new->c = c;
	new->next = *p;
	*p = new;
	return *p;
}

bool isValid(char *s)
{
	int i;
	struct stack *open_paren = NULL;

	for (i = 0; s[i] != '\0'; ++i)
		switch (s[i]) {
			case '(':
			case '[':
			case '{':
				if (push(&open_paren, s[i]) == NULL)
					exit(1);
				break;
			case ')':
				if (pop(&open_paren) != '(') {
					free_stack(open_paren);
					return false;
				}
				break;
			case ']':
				if (pop(&open_paren) != '[') {
					free_stack(open_paren);
					return false;
				}
				break;
			case '}':
				if (pop(&open_paren) != '{') {
					free_stack(open_paren);
					return false;
				}
				break;
		}
	if (open_paren != NULL) {
		free_stack(open_paren);
		return false;
	}
	return true;
}

int main()
{
	char *s[] = {"()", "()[]{}", "(]", "([)]", "{[]}"};
	size_t i;

	for (i = 0; i < sizeof(s) / sizeof(*s); ++i)
		printf("%s:\t%s\n", s[i], isValid(s[i]) == true ? "true" : "false");
	return 0;
}
