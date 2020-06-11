# [first_duplicate](./first_duplicate.c)
Given an array `a` that contains only numbers in the range from `1` to `a`'s length, find the first duplicate number for which the second occurrence has the minimal index. In other words, if there are more than 1 duplicated numbers, return the number for which the second occurrence has a smaller index than the second occurrence of the other number does. If there are no such elements, return `-1`.

## Example
* For `a = [2, 1, 3, 5, 3, 2]`, the output should be `first_duplicate(a) = 3`
* For `a = [2, 2]`, the output should be `first_duplicate(a) = 2`
* For `a = [2, 4, 3, 5, 1]`, the output should be `first_duplicate(a) = -1`

# [firstNotRepeatingCharacter](./firstNotRepeatingCharacter.js)
Given a string `s` consisting of small English letters, find and return the first instance of a non-repeating character in it. If there is no such character, return `'_'`.

## Example
* For `s = "abacabad"`, the output should be `firstNotRepeatingCharacter(s) = 'c'`
* For `s = "abacabaabacaba"`, the output should be `firstNotRepeatingCharacter(s) = '_'`

# [rotateImage](./rotateImage.js)
Given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

## Example
```
a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]

rotateImage(a) = 
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]
```

# [sudoku2](./sudoku2.py)
Given `grid` of numbers, check if grid contains a valid Sudoku puzzle. Each row, column, and sub 3x3 grid should contain all numbers 1 to 9 once. 

## Example
```
grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]

grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
        ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
        ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
```

# [is_crypt_solution](./is_crypt_solution.py)
Given array of strings `crypt` and array containing mapping of letters and digits `solution`, check whether decoded `crypt[0] + crypt[1] == crypt[2]`. Leading zeroes are invalid.

## Example
```
crypt = ["SEND", "MORE", "MONEY"]

solution = [['O', '0'],
            ['M', '1'],
            ['Y', '2'],
            ['E', '5'],
            ['N', '6'],
            ['D', '7'],
            ['R', '8'],
            ['S', '9']]

is_crypt_solution(crypt, solution) = true
```

# [two_city_sched](./two_city_sched.c)
There are `2N` people a company is planning to interview. The cost of flying the `i`-th person to city `A` is costs[i][0], and the cost of flying the `i`-th person to city `B` is `costs[i][1]`.

Return the minimum cost to fly every person to a city such that exactly `N` people arrive in each city.

## Example
```
Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
```

# [trap_water](./trap_water.c)
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

## Example
```
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```
