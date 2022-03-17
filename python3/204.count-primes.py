#
# @lc app=leetcode id=204 lang=python3
#
# [204] Count Primes
#
# https://leetcode.com/problems/count-primes/description/
#
# algorithms
# Easy (30.20%)
# Likes:    1405
# Dislikes: 474
# Total Accepted:    287.2K
# Total Submissions: 950.9K
# Testcase Example:  '10'
#
# Count the number of prime numbers less than a non-negative number, n.
# 
# Example:
# 
# 
# Input: 10
# Output: 4
# Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
# 
# 
#

# @lc code=start
from math import sqrt, floor
class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3: return 0
        flag = [True] * n
        flag[0] = flag[1] = False
        for i in range(2, floor(sqrt(n))+1):
            if flag[i]:
                for j in range(i*2, n, i):
                    flag[j] = False
        return sum(flag)
        
# @lc code=end

