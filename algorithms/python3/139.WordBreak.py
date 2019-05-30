"""
Source : https://leetcode-cn.com/problems/word-break/
Author : Lianfeng Shen
Date   : 2019-05-30
"""

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        breakj = [0]
        
        for i in range(len(s) + 1):
            for j in breakj:
                if s[j: i] in wordDict:
                    breakj.append(i)
                    break
                    
        return breakj[-1] == len(s)