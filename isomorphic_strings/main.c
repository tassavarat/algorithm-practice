#include "../leetcode.h"

bool isIsomorphic(char *s, char *t)
{
	int m1[256], m2[256], i;

	memset(m1, -1, sizeof(m1)), memset(m2, -1, sizeof(m2));
	for (i = 0; s[i]; ++i) {
		if (m1[s[i]] != m2[t[i]])
			return false;
		m1[s[i]] = m2[t[i]] = i;
	}
	return true;
}

int main()
{
	printf("%s\n", isIsomorphic("egg", "add") ? "true" : "false");
	return 0;
}
