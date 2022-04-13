package main

import "fmt"

func strstr(haystack, needle string) int {
	if needle == "" {
		return 0
	}

	var needle_len int = len(needle)
	var len_diff int = len(haystack) - needle_len
	if len_diff < 0 {
		return -1
	}

	for i := 0; i <= len_diff; i++ {
		if haystack[i:i + needle_len] == needle {
			return i
		}
	}
	return -1
}

func check(haystack, needle string, match, index int) {
	if (index != match) {
		fmt.Printf("Failed haystack: %s needle: %s expected: %d received %d\n", haystack, needle, match, index)
	}
}

func main() {
	var haystack, needle string = "hello", "ll"
	check(haystack, needle, 2, strstr(haystack, needle))

	haystack, needle = "aaaaa", "bba"
	check(haystack, needle, -1, strstr(haystack, needle))
}
