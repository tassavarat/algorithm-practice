package main

import "fmt"

func lengthOfLastWords(s string) int {
	var l int
	var i int = len(s) - 1
	for i > -1 && s[i] == ' ' {
		i--
	}
	for i > -1 && s[i] != ' ' {
		i--
		l++
	}
	return l
}

func main() {
	fmt.Printf("expected: 4 got %d\n", lengthOfLastWords("   fly me   to   the moon  "))
}
