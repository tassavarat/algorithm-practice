#include <stdio.h>
#include <string.h>

/**
 * reverseString - reverse a string
 * @s: string to reverse
 * @sSize: string size
 */
void reverseString(char *s, int sSize)
{
	int i, j;

	if (!s)
		return;
	for (i = 0, j = sSize - 1; i < j; ++i, --j)
		s[i] ^= s[j], s[j] ^= s[i], s[i] ^= s[j];
}

int main()
{
	char s[] = "hello";

	puts(s);
	reverseString(s, strlen(s));
	puts(s);
	return 0;
}
