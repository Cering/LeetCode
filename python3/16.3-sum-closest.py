#
# @lc app=leetcode id=16 lang=python3
#
# [16] 3Sum Closest
#

# @lc code=start
from typing import List
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        return self.solution1(nums, target)
        
    def solution1(self, nums: List[int], target: int) -> int:
        nums_len = len(nums)
        nums.sort()
        ret = nums[0] + nums[1] + nums[2]
        diff = abs(target-ret)
        for i in range(nums_len-2):
            left = i+1
            right = nums_len-1
            while left < right:
                three_sum = nums[i] + nums[left] + nums[right]
                if three_sum == target:
                    return three_sum

                mydiff = abs(target-three_sum)
                if mydiff < diff:
                    ret = three_sum
                    diff = mydiff

                if three_sum > target:
                    right -= 1
                else:
                    left += 1
        
        return ret

# @lc code=end

