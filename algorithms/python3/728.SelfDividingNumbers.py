"""
Source : https://leetcode-cn.com/problems/self-dividing-numbers/
Author : Lianfeng Shen
Date   : 2019-05-08
"""

class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        
        def isSDN(dividend):
            num = dividend
            while num:
                divisor, num = num % 10, num // 10
                if divisor == 0 or dividend % divisor != 0:
                    return False
            return True
            
        return [num for num in range(left, right+1) if isSDN(num)]