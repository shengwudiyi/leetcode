"""
Source : https://leetcode-cn.com/problems/balanced-binary-tree/
Author : Lianfeng Shen
Date   : 2019-06-07
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        def height(node):
            if node:
                return max(height(node.left), height(node.right)) + 1
            else:
                return 0
            
        return abs(height(root.left) - height(root.right)) < 2 and self.isBalanced(root.left) and self.isBalanced(root.right)