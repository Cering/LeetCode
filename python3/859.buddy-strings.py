#
# @lc app=leetcode id=859 lang=python3
#
# [859] Buddy Strings
#
# https://leetcode.com/problems/buddy-strings/description/
#
# algorithms
# Easy (27.81%)
# Likes:    382
# Dislikes: 241
# Total Accepted:    33.6K
# Total Submissions: 120.9K
# Testcase Example:  '"ab"\n"ba"'
#
# Given two strings A and B of lowercase letters, return true if and only if we
# can swap two letters in A so that the result equals B.
# 
# 
# 
# Example 1:
# 
# 
# 
# Input: A = "ab", B = "ba"
# Output: true
# 
# 
# 
# Example 2:
# 
# 
# Input: A = "ab", B = "ab"
# Output: false
# 
# 
# 
# Example 3:
# 
# 
# Input: A = "aa", B = "aa"
# Output: true
# 
# 
# 
# Example 4:
# 
# 
# Input: A = "aaaaaaabc", B = "aaaaaaacb"
# Output: true
# 
# 
# 
# Example 5:
# 
# 
# Input: A = "", B = "aa"
# Output: false
# 
# 
# 
# 
# Note:
# 
# 
# 0 <= A.length <= 20000
# 0 <= B.length <= 20000
# A and B consist only of lowercase letters.
# 
# 
# 
# 
# 
# 
# 
#

# @lc code=start
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        length = len(A)
        if len(B) != length:
            return False
        diff = [-1, -1]
        mdict = {}
        pos = 0
        for i in range(length):
            if A[i] != B[i]:
                if pos >= 2:
                    return False
                diff[pos] = i
                pos += 1
            mdict[A[i]] = mdict.get(A[i],0) + 1
        if pos == 0:
            for v in mdict.values():
                if v >= 2:
                    return True
            return False
        elif pos != 2:
            return False
        else:
            return A[diff[0]]==B[diff[1]] and A[diff[1]]==B[diff[0]]
        
# @lc code=end

