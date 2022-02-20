#
# @lc app=leetcode id=18 lang=python3
#
# [18] 4Sum
#

# @lc code=start
from typing import List
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        return self.solution1(nums, target)
        
    def solution1(self, nums: List[int], target: int) -> List[List[int]]:
        nums_len = len(nums)
        if nums_len < 4:
            return []
        nums.sort()

        ret = []
        for i in range(nums_len-3):
            if i>0 and nums[i]==nums[i-1]:
                continue
            j = i + 1
            for j in range(i+1, nums_len-2):
                if j>i+1 and nums[j]==nums[j-1]:
                    continue
                twosum = nums[i] + nums[j]
                left = j + 1
                right = nums_len - 1
                while left < right:
                    foursum = nums[left] + nums[right] + twosum
                    if foursum > target:
                        right -= 1
                    elif foursum < target:
                        left += 1
                    else:
                        ret.append([nums[i], nums[j], nums[left], nums[right]])
                        while left<right and nums[left+1]==nums[left]:
                            left += 1
                        while left<right and nums[right-1]==nums[right]:
                            right -= 1
                        left += 1
                        right -= 1
        
        return ret

# @lc code=end

if "__main__" == __name__:
    nums = [1,-2,-5,-4,-3,3,3,5]
    target = -11
    obj = Solution()
    print(obj.fourSum(nums,target))