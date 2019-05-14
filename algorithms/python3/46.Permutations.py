"""
Source : https://leetcode-cn.com/problems/permutations/
Author : Lianfeng Shen
Date   : 2019-05-14
"""

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        def backtrack(res, i):
            if i == len(nums):
                res.append(nums[:])
            else:
                for j in range(i, len(nums)):
                    nums[i], nums[j] = nums[j], nums[i]
                    res = backtrack(res, i+1)
                    nums[i], nums[j] = nums[j], nums[i]
            
            return res
        
        return backtrack([], 0)