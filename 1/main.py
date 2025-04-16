from typing import List


def twoSum(nums: List[int], target: int):
    numbersSet = set()

    for index1 in range(len(nums)):
        if (target - nums[index1]) in numbersSet:
            return [nums.index(target - nums[index1]), index1]
        else:
            numbersSet.add(nums[index1])

print(twoSum(nums=[3, 3], target=6))
