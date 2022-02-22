#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        return self.solution1(height)
        
    def solution1(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1
        ret = 0
        while left < right:
            area = min(height[left],height[right]) * (right-left)
            if area > ret:
                ret = area
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return ret

# @lc code=end

