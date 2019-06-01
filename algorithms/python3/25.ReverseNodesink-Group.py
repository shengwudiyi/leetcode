"""
Source : https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
Author : Lianfeng Shen
Date   : 2019-06-01
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or k == 1:
            return head
        
        p = head
            
        # nead reverse or not
        flag = False
        
        for i in range(k):
            if p:
                p = p.next
            else:
                break
        else:
            flag = True
            
        # reverse
        def reverse(node, k):
            tailnode = node
            
            prev, next = node, node.next
            for i in range(k-1):
                tmp = prev
                prev, next = next, next.next
                prev.next = tmp
                
            return prev, tailnode
            
        if flag:
            headnode, tailnode = reverse(head, k)
            tailnode.next = self.reverseKGroup(p, k)
        else:
            headnode = head
            
        return headnode