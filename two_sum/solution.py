from typing import List


def twoSum(nums: List[int], target: int) -> List[int]:
    ht = {}
    for i, n in enumerate(nums):
        comp = target - n
        if comp in ht:
            return [ht[comp], i]
        ht[n] = i


print(twoSum([2, 7, 11, 15], 9))
print(twoSum([3, 2, 4], 6))
