#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#
# https://leetcode.com/problems/reverse-integer/description/
#
# algorithms
# Easy (25.56%)
# Likes:    2642
# Dislikes: 4109
# Total Accepted:    878.4K
# Total Submissions: 3.4M
# Testcase Example:  '123'
#
# Given a 32-bit signed integer, reverse digits of an integer.
# 
# Example 1:
# 
# 
# Input: 123
# Output: 321
# 
# 
# Example 2:
# 
# 
# Input: -123
# Output: -321
# 
# 
# Example 3:
# 
# 
# Input: 120
# Output: 21
# 
# 
# Note:
# Assume we are dealing with an environment which could only store integers
# within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
# of this problem, assume that your function returns 0 when the reversed
# integer overflows.
# 
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        if x>0x7FFFFFFF or x<-0x80000000:
            return 0
        isnegative = False
        if x < 0:
            isnegative = True
            x = -x
        res = 0
        while x != 0:
            x, mod = divmod(x, 10)
            res = res*10 + mod
        if (isnegative and res>0x80000000) or (not isnegative and res>0x7FFFFFFF):
            return 0
        return -res if isnegative else res
        
# @lc code=end

