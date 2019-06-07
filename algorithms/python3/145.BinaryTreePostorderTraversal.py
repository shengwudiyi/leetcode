"""
Source : https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
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
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        stack = list()
        order = list()
        
        node = root
        last = None
        
        while node or stack:
            if node:
                stack.append(node)
                node = node.left
            else:
                if stack[-1].right and last != stack[-1].right:
                    node = stack[-1].right
                else:
                    last = stack.pop()
                    order.append(last.val)
                    
        return order