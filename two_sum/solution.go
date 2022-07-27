package main

import "fmt"

func twoSum(nums []int, target int) []int {
	var ht = make(map[int]int)

	for i, e := range nums {
		val, exist := ht[target - e]
		if exist {
			return []int{val, i}
		}
		ht[e] = i
	}
	return nil
}

func main() {
	var nums = []int {2, 7, 11, 15}

	fmt.Println(twoSum(nums, 9))

	nums = []int {3, 2, 4}
	fmt.Println(twoSum(nums, 6))
}
