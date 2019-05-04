// Source : https://leetcode-cn.com/problems/power-of-two/
// Author : Lianfeng Shen
// Date   : 2019-05-04

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & n - 1) == 0;
    }
};