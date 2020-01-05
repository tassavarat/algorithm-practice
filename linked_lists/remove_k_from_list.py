def removeKFromList(l, k):
    """Removes all nodes containing k from list

    Args:
        l: Head node
        k: Value  being removed

    Returns:
        Head of updated list
    """
    cur = tmp = l

    while cur:
        if cur.value == k and cur != l:
            tmp.next = cur.next
            cur = None
        else:
            tmp = cur
        cur = tmp.next
        if tmp.value == k:
            l = cur
            tmp = None
    return l
