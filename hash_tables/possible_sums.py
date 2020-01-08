def possible_sums(coins, quantity):
    """Finds the number of possible unique sums

    Args:
        coins: List of coin values
        quantity: List of coin quantities

    Returns:
        Amount of unique sums
    """
    tmp_s = set()
    s = set()

    for i in range(len(coins)):
        for c in range(1, quantity[i] + 1):
            tmp_s.add(coins[i] * c)
            for j in s:
                tmp_s.add(j + coins[i] * c)
        s.update(tmp_s)
    return len(s)
