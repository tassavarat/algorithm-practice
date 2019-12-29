def is_crypt_solution(crypt, solution):
    """Decrypts crypt using solution and checks if word0 + word1 == word2

    Args:
        crypt: List of strings
        solution: 2D list containing letter and corresponding numerical value

    Returns:
        True if sums are valid, otherwise False
    """
    soln_d = {}
    word = []

    for i in solution:
        soln_d[i[0]] = i[1]

    for i in range(len(crypt)):
        word.append(0)
        for j in range(len(crypt[i])):
            word[i] = word[i] * 10 + int(soln_d.get(crypt[i][j]))
            if j == 0 and len(crypt[i]) > 1 and word[i] == 0:
                return False

    if word[0] + word[1] == word[2]:
        return True
    else:
        return False
