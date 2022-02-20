#
# @lc app=leetcode id=495 lang=python3
#
# [495] Teemo Attacking
#

# @lc code=start
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        #return self.solution1(timeSeries, duration)
        return self.solution2(timeSeries, duration)
        
    def solution1(self, timeSeries: List[int], duration: int) -> int:
        if duration == 0:
            return 0

        ret = 0
        pos_cur = 0
        pos_end = -1

        for pos_time in timeSeries:
            if pos_time > pos_end:
                ret += pos_end - pos_cur + 1
            else:
                ret += pos_time - pos_cur
            pos_cur = pos_time
            pos_end = pos_cur + duration - 1
        ret += pos_end - pos_cur + 1

        return ret

    def solution2(self, timeSeries: List[int], duration: int) -> int:
        if duration == 0:
            return 0
        list_len = len(timeSeries)
        if list_len == 0:
            return 0

        ret = 0
        for i in range(list_len-1):
            ret += duration if (timeSeries[i+1]-timeSeries[i])> duration else (timeSeries[i+1]-timeSeries[i])
        ret += duration
        return ret

# @lc code=end

