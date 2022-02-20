#
# @lc app=leetcode id=567 lang=python3
#
# [567] Permutation in String
#

# @lc code=start
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        return self.solution1(s1, s2)
        
    def solution1(self, s1: str, s2: str) -> bool:
        s1_len = len(s1)
        s2_len = len(s2)
        if s1_len > s2_len: 
            return False
        
        s1_sort = ''.join(sorted(list(s1)))
        pos = 0
        while pos+s1_len <= s2_len:
            sub_s2 = ''.join(sorted(list(s2[pos:pos+s1_len])))
            if sub_s2 == s1_sort:
                return True
            pos += 1
        return False

if "__main__" == __name__:
    my = Solution()
    s1 = "aadcb"
    s2 = "zxbdacabb"
    print(my.checkInclusion(s1, s2))

# @lc code=end

