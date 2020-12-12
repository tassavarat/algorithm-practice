from collections import Counter


def firstUinqChar(s: str) -> int:
    count = Counter(s)

    for i, c in enumerate(s):
        if count[c] == 1:
            return i
    return -1


print(firstUinqChar("leetcode"))
print(firstUinqChar("loveleetcode"))
