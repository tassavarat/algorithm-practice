#include "../leetcode.h"

int singleNumber(int *nums, int numsSize)
{
	int xor = 0, i;

	for (i = 0; i < numsSize; ++i)
		xor ^= nums[i];
	return xor;
}

void check(int *arr, size_t arr_size, int soln)
{
	int i, got = singleNumber(arr, arr_size);

	printf("array: [");
	for (i = 0; i < arr_size - 1; ++i)
		printf("%d ", arr[i]);
	printf("%d]\nExpected: %d\tGot: %d\n", arr[i], soln, got);
}

int main()
{
	int arr1[] = {2, 2, 1};
	int arr2[] = {4, 1, 2, 1, 2};
	int arr3[] = {1};

	check(arr1, sizeof(arr1) / sizeof(*arr1), 1);
	check(arr2, sizeof(arr2) / sizeof(*arr2), 4);
	check(arr3, sizeof(arr3) / sizeof(*arr3), 1);
	return 0;
}
