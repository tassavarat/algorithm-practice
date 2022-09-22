package main

import "fmt"

func climbStairs(n int) int {
	if n < 4 {
		return n
	}

	var x, y int = 1, 2
	var sum int

	for ; n > 2; n-- {
		sum = x + y
		x = y
		y = sum
	}
	return sum
}

func main() {
	var n int

	n = 2
	fmt.Println("n =", n)
	fmt.Printf("Got %d\nExpected 2\n", climbStairs(n))
	n = 3
	fmt.Println("n =", n)
	fmt.Printf("Got %d\nExpected 3\n", climbStairs(n))
	n = 4
	fmt.Println("n =", n)
	fmt.Printf("Got %d\nExpected 5\n", climbStairs(n))
}
