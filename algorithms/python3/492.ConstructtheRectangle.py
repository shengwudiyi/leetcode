"""
Source : https://leetcode-cn.com/problems/construct-the-rectangle/
Author : Lianfeng Shen
Date   : 2019-06-04
"""

class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        W = 1
        L = area
        
        while W * W <= area:
            if area % W == 0:
                L = area / W
             
            W += 1
            
        return int(L), int(area / L)