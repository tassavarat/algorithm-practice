#include <stdio.h>

int maxPower(char *s)
{
	int max = 0, consec = 0, i;
	char c = '\0';

	for (i = 0; s[i]; ++i) {
		if (s[i] != c) {
			consec = 1;
			c = s[i];
		} else {
			++consec;
		}
		if (consec > max)
			max = consec;
	}
	return max;
}

int main()
{
	char *s1 = "leetcode";
	char *s2 = "abbcccddddeeeeedcba";
	char *s3 = "triplepillooooow";
	char *s4 = "tourist";

	printf("s: %s\npower %i\n", s1, maxPower(s1));
	printf("s: %s\npower %i\n", s2, maxPower(s2));
	printf("s: %s\npower %i\n", s3, maxPower(s3));
	printf("s: %s\npower %i\n", s4, maxPower(s4));
	return 0;
}
