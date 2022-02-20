#
# @lc app=leetcode id=338 lang=python3
#
# [338] Counting Bits
#

# @lc code=start
class Solution:
    def countBits(self, n: int) -> List[int]:
        #return self.solution1(n)
        return self.solution2(n)

    def solution1(self, n: int) -> List[int]:
        ret = []
        for i in range(n+1):
            ret.append(0)
            while i != 0:
                ret[-1] += 1
                i = i&(i-1)
        return ret

    def solution2(self, n: int) -> List[int]:
        ret = [0] * (n+1)
        for i in range(1, n+1):
            ret[i] = ret[i>>1] + i%2
        return ret

# @lc code=end

