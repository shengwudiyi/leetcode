"""
Source: https://leetcode-cn.com/problems/merge-intervals/
Author: Lianfeng Shen
Date:   2018-12-19
"""

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals:
            return intervals
        
        intervals.sort(key=lambda x: x.start)
        
        pre = intervals[0]
        ret = [pre]
        
        for curr in intervals[1:]:
                
            if pre.end >= curr.start:
                pre.end = max(pre.end, curr.end)
            else:
                pre = curr
                ret.append(pre)
        
        return ret
