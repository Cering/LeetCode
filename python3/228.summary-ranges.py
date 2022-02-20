#
# @lc app=leetcode id=228 lang=python3
#
# [228] Summary Ranges
#

# @lc code=start
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        return self.solution1(nums)
        
    def solution1(self, nums: List[int]) -> List[str]:
        list_len = len(nums)
        if list_len == 0:
            return []
        if list_len == 1:
            return [str(nums[0])]
        
        ret = []
        left = 0
        right = 1
        while right != list_len:
            if nums[right]-1 != nums[right-1]:
                if left == right-1:
                    ret.append(str(nums[left]))
                else:
                    ret.append(f"{nums[left]}->{nums[right-1]}")
                left = right
            right += 1
        if left == right-1:
            ret.append(str(nums[left]))
        else:
            ret.append(f"{nums[left]}->{nums[right-1]}")

        return ret

# @lc code=end

