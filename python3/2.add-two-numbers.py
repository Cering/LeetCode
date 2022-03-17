#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#
# https://leetcode.com/problems/add-two-numbers/description/
#
# algorithms
# Medium (32.29%)
# Likes:    6484
# Dislikes: 1689
# Total Accepted:    1.1M
# Total Submissions: 3.5M
# Testcase Example:  '[2,4,3]\n[5,6,4]'
#
# You are given two non-empty linked lists representing two non-negative
# integers. The digits are stored in reverse order and each of their nodes
# contain a single digit. Add the two numbers and return it as a linked list.
# 
# You may assume the two numbers do not contain any leading zero, except the
# number 0 itself.
# 
# Example:
# 
# 
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        pos1, pos2 = l1, l2
        inc = 0
        while pos2:
            inc, pos1.val = divmod(pos1.val+pos2.val+inc, 10)
            if not pos1.next:
                pos1.next = pos2.next
                break
            pos2 = pos2.next
            if not pos2:
                break
            pos1 = pos1.next
        
        while pos1 and inc>0:
            if not pos1.next:
                pos1.next = ListNode(inc)
                break
            pos1 = pos1.next
            inc, pos1.val = divmod(pos1.val+inc, 10)
        return l1
        
# @lc code=end

