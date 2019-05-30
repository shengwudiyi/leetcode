"""
Source : https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
Author : Lianfeng Shen
Date   : 2019-05-30
"""

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        def partition(nums, p, r, k):
            pivot = nums[r]
            
            q = j = p
            while j < r:
                if nums[j] < pivot:
                    nums[q], nums[j] = nums[j], nums[q]
                    q += 1
                    
                j += 1
            
            nums[q], nums[r] = nums[r], nums[q]
            
            if k == q:
                return nums[k]
            elif k > q:
                return partition(nums, q+1, r  , k)
            else:
                return partition(nums, p  , q-1, k)
            
        return partition(nums, 0, len(nums)-1, len(nums)-k)
