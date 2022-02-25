#
# @lc app=leetcode id=34 lang=python3
#
# [34] Find First and Last Position of Element in Sorted Array
#
# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#
# algorithms
# Medium (39.67%)
# Likes:    9431
# Dislikes: 272
# Total Accepted:    997.6K
# Total Submissions: 2.5M
# Testcase Example:  '[5,7,7,8,8,10]\n8'
#
# Given an array of integers nums sorted in non-decreasing order, find the
# starting and ending position of a given target value.
# 
# If target is not found in the array, return [-1, -1].
# 
# You must write an algorithm with O(log n) runtime complexity.
# 
# 
# Example 1:
# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]
# Example 2:
# Input: nums = [5,7,7,8,8,10], target = 6
# Output: [-1,-1]
# Example 3:
# Input: nums = [], target = 0
# Output: [-1,-1]
# 
# 
# Constraints:
# 
# 
# 0 <= nums.length <= 10^5
# -10^9 <= nums[i] <= 10^9
# nums is a non-decreasing array.
# -10^9 <= target <= 10^9
# 
# 
#

# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return self.solution1(nums, target)
        
    def solution1(self, nums: List[int], target: int) -> List[int]:
        nums_len = len(nums)
        if nums_len == 0:
            return [-1, -1]

        #查最左边的target位置
        left = 0
        right = nums_len - 1
        spos = -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            elif mid>0 and nums[mid]==nums[mid-1]:
                #左侧仍存在target值，继续向左缩小区间
                right = mid - 1
            else:
                spos = mid
                left +=1
                right -= 1

        #从spos开始，查最右边的target位置
        left = min(spos, 0)
        right = nums_len - 1
        epos = -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            elif mid<nums_len-1 and nums[mid]==nums[mid+1]:
                #右侧仍存在target值，继续向右缩小区间
                left = mid + 1
            else:
                epos = mid
                left +=1
                right -= 1

        return [spos, epos]

# @lc code=end