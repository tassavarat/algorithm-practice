#include "../leetcode.h"

int maxProfit(int *prices, int pricesSize)
{
	int profit = 0, i;

	for (i = 1; i < pricesSize; ++i) {
		if (prices[i] > prices[i - 1]) {
			profit += prices[i] - prices[i - 1];
		}
	}
	return profit;
}

void check(int *arr, size_t size, int soln)
{
	int got = maxProfit(arr, size), i;

	putchar('[');
	for (i = 0; i < size - 1; ++i) {
		printf("%d ", arr[i]);
	}
	printf("%d]\nGot: %d\tExpected: %d\n", arr[i], got, soln);
}

int main()
{
	int arr1[] = {7, 1, 5, 3, 6, 4};
	int arr2[] = {1, 2, 3, 4, 5};
	int arr3[] = {7, 6, 4, 3, 1};

	check(arr1, sizeof(arr1) / sizeof(*arr1), 7);
	check(arr2, sizeof(arr2) / sizeof(*arr2), 4);
	check(arr3, sizeof(arr3) / sizeof(*arr3), 0);
	return 0;
}
