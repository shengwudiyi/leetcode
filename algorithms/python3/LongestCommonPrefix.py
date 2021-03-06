"""
Source: https://leetcode-cn.com/problems/longest-common-prefix/description/
Author: Lianfeng Shen
Date:   2018-08-28
"""

class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        prefix = min(strs, key=len)
        for i, ch in enumerate(prefix):
            for _str in strs:
                if ch != _str[i]:
                    return prefix[: i]
        return prefix
