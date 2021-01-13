#include "../leetcode.h"

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	int i = m - 1, j = n - 1, k = nums1Size - 1;

	while (i > -1 && j > -1) {
		if (nums1[i] <= nums2[j])
			nums1[k--] = nums2[j--];
		else
			nums1[k--] = nums1[i--];
	}

	while (j > -1)
		nums1[j--] = nums2[j];
}

int main()
{
	/* int nums1[] = {1, 2, 3, 0, 0, 0}, nums2[] = {2, 5, 6}, i; */
	/* int nums1Size = sizeof(nums1) / sizeof(*nums1), nums2Size = sizeof(nums2) / sizeof(*nums2), m = 3, n = 3; */
	int nums1[] = {5, 9, 12, 13, 0, 0, 0, 0}, nums2[] = {1, 8, 11, 14}, i;
	int nums1Size = sizeof(nums1) / sizeof(*nums1), nums2Size = sizeof(nums2) / sizeof(*nums2), m = 4, n = 4;

	merge(nums1, nums1Size, m, nums2, nums2Size, n);

	for (i = 0; i < nums1Size; ++i)
		printf("%i ", nums1[i]);
	putchar('\n');
}
