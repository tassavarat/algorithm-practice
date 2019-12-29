def sudoku2(grid):
    """Checks whether grid represents valid Sudoku puzzle

    Args:
        grid: 2D array

    Returns:
        True if valid Sudoku puzzle, otherwise False
    """
    for i, row in enumerate(grid):
        s = set()
        if i % 3 == 0:
            sub0 = set()
            sub1 = set()
            sub2 = set()
        for j,  elem in enumerate(row):
            if elem == '.':
                continue
            if elem in s:
                return False
            s.add(elem)
            if j < 3:
                if elem in sub0:
                    return False
                sub0.add(elem)
            elif j < 6:
                if elem in sub1:
                    return False
                sub1.add(elem)
            elif j > 5:
                if elem in sub2:
                    return False
                sub2.add(elem)

    for i in range(len(grid)):
        s = set()
        for j in range(len(grid)):
            if grid[j][i] == '.':
                continue
            if grid[j][i] in s:
                return False
            s.add(grid[j][i])
    return True
