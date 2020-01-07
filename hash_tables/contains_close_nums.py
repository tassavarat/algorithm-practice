def contains_close_nums(nums, k):
    """Checks if distance of two duplicate values is less than or equal to k

    Args:
        nums: List containing numbers
        k: Acceptable distance

    Returns:
        True if distance less or equal to k, otherwise False
    """
    pos = {}

    for i, n in enumerate(nums):
        if n in pos and i - pos[n] <= k:
            return True
        pos[n] = i
    return False
