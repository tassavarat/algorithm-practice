# [remove_k_from_list](./remove_k_from_list.c)
Given a singly linked list of integers `l` and an integer `k`, remove all elements from list `l` that have a value equal to `k`.

## Example
* For `l = [3, 1, 2, 3, 4, 5]` and `k = 3`, the output should be `remove_k_from_list(l, k) = [1, 2, 4, 5]`
* For `l = [1, 2, 3, 4, 5, 6, 7]` and `k = 10`, the output should be `remove_k_from_list(l, k) = [1, 2, 3, 4, 5, 6, 7]`

# [is_list_palindrome](./is_list_palindrome.c)
Given a singly linked list of integers, determine whether or not it's a palindrome.

## Example
* For `l = [0, 1, 0]`, the output should be `is_list_palindrome(l) = true`
* For `l = [1, 2, 2, 3]`, the output should be `is_list_palindrome(l) = false`

# [add_two_huge_numbers](./add_two_huge_numbers.c)
Given 2 numbers represented in linked lists. Add their values together and return the result in the same format. Each linked list element is a number from 0 to 9999. Each value has 4 digits, missing digits are leading zeroes.

## Example
* For `a = [9876, 5432, 1999]` and `b = [1, 8001]`, the output should be `add_two_huge_numbers(a, b) = [9876, 5434, 0]`
* For `a = [123, 4, 5]` and `b = [100, 100, 100]`, the output should be `add_two_huge_numbers(a, b) = [223, 104, 105]`
