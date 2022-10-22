package main

import "fmt"

func singleNumber(nums []int) int {
	var xor int

	for i := 0; i < len(nums); i++ {
		xor ^= nums[i]
	}
	return xor
}

func check(arr []int, soln int) {
	var got int = singleNumber(arr)
	var i int

	fmt.Print("Array: [")
	for i = 0; i < len(arr) - 1; i++ {
		fmt.Printf("%d ", arr[i])
	}
	fmt.Printf("%d]\nExpected: %d\tGot: %d\n", arr[i], soln, got)
}

func main() {
	check([]int{2, 2, 1}, 1)
	check([]int{4, 1, 2, 1, 2}, 4)
	check([]int{1}, 1)
}
