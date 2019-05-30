"""
Source : https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
Author : Lianfeng Shen
Date   : 2019-05-30
"""

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i, j = 0, len(numbers)-1
        
        while i < j:
            if numbers[i] + numbers[j] == target:
                break
                
            if numbers[i] + numbers[j] > target:
                j -= 1
            else:
                i += 1
                
        return [i+1, j+1]