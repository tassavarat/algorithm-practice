from queue import LifoQueue


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    stack1 = LifoQueue()
    cur = l1
    while cur:
        stack1.put(cur.val)
        cur = cur.next

    cur = l2
    stack2 = LifoQueue()
    while cur:
        stack2.put(cur.val)
        cur = cur.next

    tmp = lsum = None
    num = 0
    while not stack1.empty() or not stack2.empty() or num != 0:
        lsum = ListNode()
        if not stack1.empty():
            num += stack1.get()
        if not stack2.empty():
            num += stack2.get()
        num, lsum.val = divmod(num, 10)
        lsum.next = tmp
        tmp = lsum
    return lsum


def lsttoll(a: list):
    for i in range(len(a)):
        cur = ListNode(a[i])
        if i == 0:
            tmp = l1 = cur
        tmp.next = tmp = cur
    return l1


lsum = addTwoNumbers(lsttoll([7, 2, 4, 3]), lsttoll([5, 6, 4]))
while(lsum):
    print(lsum.val)
    lsum = lsum.next
