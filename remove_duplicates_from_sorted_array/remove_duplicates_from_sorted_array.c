#include "../leetcode.h"

int removeDuplicates(int *nums, int numsSize)
{
	if (numsSize == 0)
		return 0;

	int i, j = 1;

	for (i = 1; i < numsSize; ++i)
		if (nums[i] != nums[i - 1]) {
			nums[j] = nums[i];
			++j;
		}
	return j;
}

int main()
{
	int num1[] = {1, 1, 2};
	int num2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	int numsSize, i;

	numsSize = removeDuplicates(num1, sizeof(num1) / sizeof(*num1));
	for (i = 0; i < numsSize; ++i)
		printf("%i ", num1[i]);
	putchar('\n');
	numsSize = removeDuplicates(num2, sizeof(num2) / sizeof(*num2));
	for (i = 0; i < numsSize; ++i)
		printf("%i ", num2[i]);
	putchar('\n');
	return 0;
}
