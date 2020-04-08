"""
Source : https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None
        
        index = inorder.index(preorder[0])
        
        root = TreeNode(preorder[0])
        root.left  = self.buildTree(preorder[1      : 1+index], inorder[       : index])
        root.right = self.buildTree(preorder[1+index:        ], inorder[index+1:      ])
        
        return root