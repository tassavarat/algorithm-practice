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

void print_arr(const int *arr, const size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
		printf("%i ", arr[i]);
	putchar('\n');
}

int main()
{
	int num1[] = {1, 1, 2};
	int num2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

	print_arr(num1, removeDuplicates(num1, sizeof(num1) / sizeof(*num1)));
	print_arr(num2, removeDuplicates(num2, sizeof(num2) / sizeof(*num2)));
	return 0;
}
