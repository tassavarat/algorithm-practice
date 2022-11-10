package main

import "fmt"

func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	var j int = 1
	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i - 1] {
			nums[j] = nums[i]
			j++
		}
	}
	return j
}

func print_arr(arr []int, n int) {
	for i := 0; i < n; i++ {
		fmt.Printf("%d ", arr[i])
	}
	fmt.Printf("\n")
}

func main() {
	var arr1 = []int{1, 1, 2}
	var arr2 = []int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}

	print_arr(arr1, removeDuplicates(arr1))
	print_arr(arr2, removeDuplicates(arr2))
}
