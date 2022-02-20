#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ret = []
        self.func1(root, ret)
        return ret

    def func1(self, node, outlist):
        if not node:
            return
        if node.left:
            self.func1(node.left, outlist)
        outlist.append(node.val)
        if node.right:
            self.func1(node.right, outlist)
        
# @lc code=end

