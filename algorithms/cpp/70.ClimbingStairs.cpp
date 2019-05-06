// Source : https://leetcode-cn.com/problems/climbing-stairs/
// Author : Lianfeng Shen
// Date   : 2019-05-06

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        } else {
            int f = 1, s = 2;
            while(n-- > 2) {
                s = f + s;
                f = s - f;
            }
            return s;
        }
    }
};