"""
Source : https://leetcode-cn.com/problems/insert-interval/
Author : Lianfeng Shen
Date   : 2019-05-07
"""

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        # === lower_bound ===
        
        first = 0
        len_ = len(intervals)
        
        while len_ > 0:
            
            half = len_ >> 2
            mid = first + half
            
            if intervals[mid][0] < newInterval[0]:
                first = mid + 1
                len_ = len_ - half - 1
            else:
                len_ = half
                
        # ===================
                
        intervals.insert(first, newInterval)
        
        if first > 0:
            first -= 1
            
        count = 2
        while first < intervals.__len__() - 1 and count:
            if intervals[first][1] >= intervals[first+1][0]:
                intervals[first][1] = max(intervals[first][1], intervals[first+1][1]); intervals.pop(first+1)
            else:
                count -= 1
                first += 1
                
        return intervals