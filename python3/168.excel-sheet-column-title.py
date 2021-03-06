#
# @lc app=leetcode id=168 lang=python3
#
# [168] Excel Sheet Column Title
#
# https://leetcode.com/problems/excel-sheet-column-title/description/
#
# algorithms
# Easy (29.88%)
# Likes:    885
# Dislikes: 184
# Total Accepted:    192.2K
# Total Submissions: 643.1K
# Testcase Example:  '1'
#
# Given a positive integer, return its corresponding column title as appear in
# an Excel sheet.
# 
# For example:
# 
# 
# ⁠   1 -> A
# ⁠   2 -> B
# ⁠   3 -> C
# ⁠   ...
# ⁠   26 -> Z
# ⁠   27 -> AA
# ⁠   28 -> AB 
# ⁠   ...
# 
# 
# Example 1:
# 
# 
# Input: 1
# Output: "A"
# 
# 
# Example 2:
# 
# 
# Input: 28
# Output: "AB"
# 
# 
# Example 3:
# 
# 
# Input: 701
# Output: "ZY"
# 
#

# @lc code=start
class Solution:
    def convertToTitle(self, n: int) -> str:
        res = []
        while n != 0:
            n, mod = divmod(n, 26)
            if mod == 0:
                n, mod = n-1, 26
            res.append(chr(ord('A')+mod-1))
        res.reverse()
        return ''.join(res)
        
        
# @lc code=end

