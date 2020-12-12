#include "../leetcode.h"

int firstUniqChar(char *s)
{
	int count[26] = {0}, i;

	for (i = 0; s[i]; ++i)
		++count[s[i] - 'a'];
	for (i = 0; s[i]; ++i)
		if (count[s[i] - 'a'] == 1)
			return i;
	return -1;
}

int main()
{
	printf("%i\n", firstUniqChar("leetcode"));
	printf("%i\n", firstUniqChar("loveleetcode"));
	printf("%i\n", firstUniqChar("aabbcc"));
	return 0;
}
