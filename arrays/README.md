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
