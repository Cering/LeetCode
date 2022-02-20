#
# @lc app=leetcode id=145 lang=python3
#
# [145] Binary Tree Postorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ret = []
        self.solution1(root, ret)
        return ret

    def solution1(self, node, outlist):
        if not node:
            return
        if node.left:
            self.solution1(node.left, outlist)
        if node.right:
            self.solution1(node.right, outlist)
        outlist.append(node.val)
        
# @lc code=end

