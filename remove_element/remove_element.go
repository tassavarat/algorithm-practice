package main

import "fmt"

func removeElement(nums []int, val int) int {
	var f, b int = 0, len(nums)

	for f < b {
		if nums[f] == val {
			nums[f] = nums[b - 1]
			b--
		} else {
			f++
		}
	}
	return b
}

func check(ret_num []int, k int, check_num []int, check_k int) {
	if k != check_k {
		fmt.Printf("Failed\n\n")
		return
	}
	for i, v := range ret_num {
		if v != check_num[i] {
			fmt.Println("Failed\n\n")
			return
		}
	}
	fmt.Println()
}

func test(nums []int, val int) (ret_num []int, k int) {
	fmt.Println("nums:", nums)
	fmt.Println("val:", val)
	k = removeElement(nums , val)
	ret_num = nums[:k]
	// fmt.Println("nums:", nums)
	fmt.Println("ret_num:", ret_num)
	fmt.Println("k:", k)
	return
}

func main() {
	var ret_num []int
	var k int
	ret_num, k = test([]int{3, 2, 2, 3}, 3)
	check(ret_num, k, []int{2, 2}, 2)

	ret_num, k = test([]int{0, 1, 2, 2, 3, 0, 4, 2}, 2)
	check(ret_num, k, []int{0, 1, 4, 0, 3}, 5)

	ret_num, k = test([]int{}, 0)
	check(ret_num, k, []int{}, 0)

	ret_num, k = test([]int{1}, 1)
	check(ret_num, k, []int{}, 0)

	ret_num, k = test([]int{3, 3}, 3)
	check(ret_num, k, []int{}, 0)
}
