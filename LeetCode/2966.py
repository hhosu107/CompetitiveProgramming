from queue import PriorityQueue
import collections


class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        ret = []
        for i in range(0, len(nums), 3):
            if nums[i] + k < nums[i + 2]:
                return []
            ret.append(nums[i : i + 3])
        return ret
