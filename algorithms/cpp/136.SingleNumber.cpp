// Source : https://leetcode-cn.com/problems/single-number/
// Author : Lianfeng Shen
// Date   : 2019-05-04

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int solution = 0;
        for (int num: nums) {
            solution ^= num;
        }
        return solution;
    }
};