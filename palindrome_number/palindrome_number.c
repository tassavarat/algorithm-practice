#include "../leetcode.h"

bool isPalindrome(int x)
{
	if (x < 0)
		return 0;

	int i = x, rev = x % 10;

	while (i /= 10)
		rev = rev * 10 + i % 10;
	return x == rev;
}

int main()
{
	int n[] = {123, 121, -121, 10, -101, 1234567899};
	size_t i;

	for (i = 0; i < sizeof(n) / sizeof(*n); ++i)
		printf("%*i %s pallindrome\n", 8, n[i], isPalindrome(n[i]) == 1 ? "is" : "isn't");
	return 0;
}
