"""
Source : https://leetcode-cn.com/problems/invert-binary-tree/
Author : Lianfeng Shen
Date   : 2019-05-07
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root