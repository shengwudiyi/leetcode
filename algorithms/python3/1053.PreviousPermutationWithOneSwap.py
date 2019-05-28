"""
Source : https://leetcode-cn.com/problems/previous-permutation-with-one-swap/
Author : Lianfeng Shen
Date   : 2019-05-28
"""

class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        
        for i in range(len(A)-2, -1, -1):
            if A[i] > A[i+1]:
                break
        else:
            return A
        
        for j in range(len(A)-1, i, -1):
            if A[j] < A[i]:
                break
                
        while A[j] == A[j-1]:
            j -= 1
                
        A[i], A[j] = A[j], A[i]
        return A
