package main

import "fmt"

func searchInsert(nums []int, target int) int {
	var l, r int = 0, len(nums) - 1
	var m int

	for l <= r {
		m = (l + r) / 2
		if nums[m] == target {
			return m
		} else if nums[m] < target {
			l = m + 1
		} else {
			r = m - 1;
		}
	}
	return l;
}

func main() {
	var nums = []int{1, 3, 5, 6}

	fmt.Printf("index:%d\texpected: 2\n", searchInsert(nums, 5));
	fmt.Printf("index:%d\texpected: 1\n", searchInsert(nums, 2));
	fmt.Printf("index:%d\texpected: 4\n", searchInsert(nums, 7));
	fmt.Printf("index:%d\texpected: 0\n", searchInsert(nums, 0));
	fmt.Printf("index:%d\texpected: 1\n", searchInsert(nums[:2], 2));
}
