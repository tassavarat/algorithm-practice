package main

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	var cur, next *ListNode = head, head.Next

	for next != nil {
		if cur.Val == next.Val {
			next = next.Next
			cur.Next = next
		} else {
			cur = cur.Next
			next = next.Next
		}
	}
	return head
}

func print_llist(head *ListNode) {
	var cur *ListNode = head

	for ; cur != nil; cur = cur.Next {
		if cur == head {
			fmt.Printf("%d", cur.Val)
		} else {
			fmt.Printf("->%d", cur.Val);
		}
	}
	fmt.Println()
}

func append_ll(n int, tail *ListNode) *ListNode {
	var new_node = new(ListNode)

	new_node.Val = n
	tail.Next = new_node
	return tail.Next
}

func arr_to_llist(arr []int) *ListNode {
	var head = new(ListNode)
	var tail *ListNode = head

	head.Val = arr[0]
	for i := 1; i < len(arr); i++ {
		tail = append_ll(arr[i], tail)
	}
	return head
}

func arr_to_llist_print_dedup(arr []int) {
	var head *ListNode = arr_to_llist(arr)

	fmt.Println("Given linked list:")
	print_llist(head)
	deleteDuplicates(head)
	fmt.Println("Deduped linked list:")
	print_llist(head)
}

func main() {
	arr_to_llist_print_dedup([]int{1, 1, 2})
	arr_to_llist_print_dedup([]int{1, 1, 2, 3, 3})
	arr_to_llist_print_dedup([]int{1, 1, 1})
}
