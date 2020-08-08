#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool detectCapitalUse(char *word)
{
	int i;

	if (isupper(*word) != 0 && isupper(*(word + 1)) != 0) {
		for (i = 2; word[i] != '\0'; ++i)
			if (isupper(word[i]) == 0)
				return false;
	} else {
		for (i = 1; word[i] != '\0'; ++i)
			if (isupper(word[i]) != 0)
				return false;
	}
	return true;
}

int main()
{
	char *s1 = "USA";
	char *s2 = "leetcode";
	char *s3 = "Google";
	char *s4 = "I";

	printf("%s\n", detectCapitalUse(s1) ? "true" : "false");
	printf("%s\n", detectCapitalUse(s2) ? "true" : "false");
	printf("%s\n", detectCapitalUse(s3) ? "true" : "false");
	printf("%s\n", detectCapitalUse(s4) ? "true" : "false");
	return 0;
}
