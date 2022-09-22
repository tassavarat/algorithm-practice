#include "../leetcode.h"

int climbStairs(int n)
{
	if (n < 4)
		return n;

	int x = 1, y = 2, sum;

	while (n-- > 2) {
		sum = x + y;
		x = y, y = sum;
	}
	return sum;
}

int main()
{
	int n;

	n = 2;
	printf("n = %d\n", n);
	printf("Got %d\nExpected 2\n", climbStairs(n));
	n = 3;
	printf("n = %d\n", n);
	printf("Got %d\nExpected 3\n", climbStairs(n));
	n = 4;
	printf("n = %d\n", n);
	printf("Got %d\nExpected 5\n", climbStairs(n));
	return 0;
}
