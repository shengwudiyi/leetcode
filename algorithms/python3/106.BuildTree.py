"""
Source : https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
Author : Lianfeng Shen
Date   : 2019-06-02
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder:
            return None
        
        index = inorder.index(postorder[-1])
        
        root = TreeNode(postorder[-1])
        root.left  = self.buildTree(inorder[       : index], postorder[     : index])
        root.right = self.buildTree(inorder[index+1:      ], postorder[index: -1   ])
        
        return root