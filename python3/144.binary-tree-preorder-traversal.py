#
# @lc app=leetcode id=144 lang=python3
#
# [144] Binary Tree Preorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ret = []
        self.solution1(root, ret)
        return ret

    def solution1(self, node, outlist):
        if not node:
            return
        outlist.append(node.val)
        if node.left:
            self.solution1(node.left, outlist)
        if node.right:
            self.solution1(node.right, outlist)
        
# @lc code=end

