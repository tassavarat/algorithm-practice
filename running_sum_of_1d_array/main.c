#include "../leetcode.h"

int *runningSum(int *nums, int numsSize, int *returnSize)
{
	int *sum, i;

	*returnSize = numsSize;
	sum = malloc(numsSize * sizeof(*sum));
	if (!sum)
		return NULL;

	for (i = 1, sum[0] = nums[0]; i < numsSize; ++i)
		sum[i] = sum[i - 1] + nums[i];
	return sum;
}

void printarr(int *arr, int size)
{
	int i;

	for (i = 0; i < size; ++i)
		printf(" %i", arr[i]);
	putchar('\n');
}

int main()
{
	int nums[] = {3, 1, 2, 10, 1}, numsSize = sizeof(nums) / sizeof(*nums), returnSize, *sum;

	printf("nums =");
	printarr(nums, numsSize);

	sum = runningSum(nums, numsSize, &returnSize);

	printf("sum =");
	printarr(sum, returnSize);
	free(sum);
}
