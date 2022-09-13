package main

import "fmt"

func plusOne(digits []int) []int {
	for i := len(digits) - 1; i > -1; i-- {
		if digits[i] == 9 {
			digits[i] = 0
		} else  {
			digits[i]++
			return digits
		}
	}

	return append([]int{1}, digits...)
}

func main() {
	var digits = []int{1, 2, 3}

	fmt.Println(digits)
	fmt.Println(plusOne(digits))

	digits = []int{4, 3, 2, 1}
	fmt.Println(digits)
	fmt.Println(plusOne(digits))

	digits = []int{9}
	fmt.Println(digits)
	fmt.Println(plusOne(digits))

	digits = []int{9, 9, 9}
	fmt.Println(digits)
	fmt.Println(plusOne(digits))

}
