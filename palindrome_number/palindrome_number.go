package main

import "fmt"

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	var i, rev int = x / 10, x % 10

	for i > 0 {
		rev = rev * 10 + i % 10
		i /= 10
	}
	return x == rev
}

func main () {
	var x = []int{123, 121, -121, 10, -101, 1234567899}

	for _, v := range x {
		if isPalindrome(v) == true {
			fmt.Printf("%*d is a pallindrome\n", 8, v)
		} else {
			fmt.Printf("%*d is not a pallindrome\n", 8, v)
		}
	}
}
