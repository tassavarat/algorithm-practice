package main

import "fmt"

func maxProfit(prices []int) int {
	var profit int

	for i := 1; i < len(prices); i++ {
		if prices[i] > prices[i - 1] {
			profit += prices[i] - prices[i - 1]
		}
	}
	return profit
}

func check(arr []int, soln int) {
	var got int = maxProfit(arr)
	var i int

	fmt.Print("[")
	for i = 0; i < len(arr) - 1; i++ {
		fmt.Printf("%d ", arr[i])
	}
	fmt.Printf("%d]\nGot: %d\tExpected: %d\n", arr[i], got, soln)
}

func main() {
	check([]int{7, 1, 5, 3, 6, 4}, 7)
	check([]int{1, 2, 3, 4, 5}, 4)
	check([]int{7, 6, 4, 3, 1}, 0)
}
