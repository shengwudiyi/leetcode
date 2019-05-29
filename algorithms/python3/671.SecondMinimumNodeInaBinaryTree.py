"""
Source : https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/
Author : Lianfeng Shen
Date   : 2019-05-29
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        self.ret = 0
        
        def dfs(node):
            if not node:
                return
            
            if node.val != root.val and (self.ret == 0 or node.val < self.ret):
                self.ret = node.val
                
            dfs(node.left)
            dfs(node.right)
        
        dfs(root)
        
        if self.ret == 0:
            return -1
        else:
            return self.ret