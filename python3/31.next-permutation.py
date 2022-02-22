#
# @lc app=leetcode id=31 lang=python3
#
# [31] Next Permutation
#

# @lc code=start
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        self.solution1(nums)

    def solution1(self, nums: List[int]) -> None:
        nums_len = len(nums)
        if nums_len <= 1:
            return

        #找到逆序第一个下降点
        pos = nums_len - 2
        while pos>=0 and nums[pos]>=nums[pos+1]:
            pos -= 1
        if pos < 0:
            nums.reverse()
            return

        #找到逆序第一个大于下降点的位置，交换
        swap = nums_len - 1
        while swap>pos and nums[swap]<=nums[pos]:
            swap -= 1
        nums[pos], nums[swap] = nums[swap], nums[pos]

        #对下降点右侧的数值升序排序，使变更点右侧数值最小
        #注意: pos和swap交换后，并不会影响pos+1之后的降序状态
        left = pos + 1
        right = nums_len - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
        
# @lc code=end

