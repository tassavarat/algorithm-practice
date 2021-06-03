Given a string s containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'[' and `']'``, determine if the input string is valid.

An input string is valid if:

	1. Open brackets must be closed by the same type of brackets.
	2. Open brackets must be closed in the correct order.

__Example 1:__
```
Input: s = "()"
Output: true
```

__Example 2:__
```
Input: s = "()[]{}"
Output: true
```

__Example 3:__
```
Input: s = "(]"
Output: false
```

__Example 4:__
```
Input: s = "([)]"
Output: false
```

__Example 5:__
```
Input: s = "{[]}"
Output: true
```
