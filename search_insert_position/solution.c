#include "../leetcode.h"

int searchInsert(int *nums, int numsSize, int target) {
	int l = 0, r = numsSize - 1, m;

	while (l <= r) {
		m = (l + r) / 2;
		if (nums[m] == target)
			return m;
		else if (nums[m] < target)
			l = m + 1;
		else
			r = m - 1;
	}
	return l;
}

int main() {
	int nums1[] = {1, 3, 5, 6};
	int numsSize1 = (sizeof(nums1) / sizeof(*nums1));
	int nums2[] = {1, 3};
	int numsSize2 = (sizeof(nums2) / sizeof(*nums2));

	printf("index:%d\texpected: 2\n", searchInsert(nums1, numsSize1, 5));
	printf("index:%d\texpected: 1\n", searchInsert(nums1, numsSize1, 2));
	printf("index:%d\texpected: 4\n", searchInsert(nums1, numsSize1, 7));
	printf("index:%d\texpected: 0\n", searchInsert(nums1, numsSize1, 0));
	printf("index:%d\texpected: 1\n", searchInsert(nums2, numsSize2, 2));
	return 0;
}
