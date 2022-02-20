#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#

# @lc code=start
from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        return self.solution1(nums)
        
    def solution1(self, nums: List[int]) -> List[List[int]]:
        nums_len = len(nums)
        if nums_len < 3:
            return []
        
        nums.sort()
        if nums[0]>0 or nums[-1]<0:
            return []

        ret = []
        for i in range(0, nums_len-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            target = -nums[i]
            left = i+1
            right = nums_len-1
            while left < right:
                twosum = nums[left]+nums[right]
                if twosum < target:
                    left += 1
                elif twosum > target:
                    right -= 1
                else:
                    tmp = [nums[left], nums[right], nums[i]]
                    ret.append(tmp)
                    while left<right and nums[left]==nums[left+1]:
                        left += 1
                    while left<right and nums[right]==nums[right-1]:
                        right -=1
                    left += 1
                    right -=1

        return ret

if "__main__" == __name__:
    nums = [-1,0,1,2,-1,-4,-2,-3,3,0,4]
    obj = Solution()
    print(obj.threeSum(nums))

# @lc code=end

