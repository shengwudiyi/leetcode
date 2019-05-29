"""
Source : https://leetcode-cn.com/problems/partition-array-into-disjoint-intervals/
Author : Lianfeng Shen
Date   : 2019-05-29
"""

class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        
        lmax = A[0]; l = 0
        nmax = A[0]
        for i in range(len(A)):
            if A[i] < lmax:
                lmax = nmax; l = i
            if A[i] > nmax:
                nmax = A[i]
                
        return l + 1