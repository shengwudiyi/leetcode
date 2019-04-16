"""
Source: https://leetcode-cn.com/problems/divide-two-integers/
Author: Lianfeng Shen
Date:   2019-04-16
"""


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        sign = (dividend < 0) == (divisor < 0)
        if dividend < 0:
            dividend = -dividend
        if divisor < 0:
            divisor = -divisor

        result = 0
        i = 1
        while (divisor << 1) <= dividend:
            i = i << 1
            divisor = divisor << 1

        while i > 0 and dividend:
            if divisor <= dividend:
                result += i
                dividend -= divisor
            divisor = divisor >> 1
            i = i >> 1

        if not sign:
            result = -result

        return min(result, (1 << 31) - 1)
