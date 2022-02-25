#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return self.solution1(nums, target)
        
    def solution1(self, nums: List[int], target: int) -> int:
        ret = -1
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                ret = mid
                break
            elif nums[left] == target:
                ret = left
                break
            elif nums[right] == target:
                ret = right
                break
            #拐点在mid右边, 左边升序排列
            elif nums[mid] > nums[left]:
                if nums[left] < target < nums[mid]:
                    #target处于左边区间
                    right = mid - 1
                else:
                    #target处于右边区间
                    left = mid + 1
            #拐点在mid左边，右边升序排列
            else:
                if nums[mid] < target < nums[right]:
                    #target处于右边区间
                    left = mid + 1
                else:
                    #target处于左边区间
                    right = mid - 1
        return ret

# @lc code=end