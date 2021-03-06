#
# @lc app=leetcode id=665 lang=python3
#
# [665] Non-decreasing Array
#
# https://leetcode.com/problems/non-decreasing-array/description/
#
# algorithms
# Easy (19.33%)
# Likes:    1325
# Dislikes: 307
# Total Accepted:    69.2K
# Total Submissions: 358.2K
# Testcase Example:  '[4,2,3]'
#
# 
# Given an array with n integers, your task is to check if it could become
# non-decreasing by modifying at most 1 element.
# 
# 
# 
# We define an array is non-decreasing if array[i]  holds for every i (1 
# 
# Example 1:
# 
# Input: [4,2,3]
# Output: True
# Explanation: You could modify the first 4 to 1 to get a non-decreasing
# array.
# 
# 
# 
# Example 2:
# 
# Input: [4,2,1]
# Output: False
# Explanation: You can't get a non-decreasing array by modify at most one
# element.
# 
# 
# 
# Note:
# The n belongs to [1, 10,000].
# 
#

# @lc code=start
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        cnt = 0
        nLen = len(nums)
        for i in range(1, nLen):
            if nums[i] >= nums[i-1]:
                continue
            if cnt == 1:
                return False
            if i==1 or nums[i]>=nums[i-2]:
                nums[i-1] = nums[i]
            else:
                nums[i] = nums[i-1]
            cnt += 1
        return cnt <= 1

        
# @lc code=end

