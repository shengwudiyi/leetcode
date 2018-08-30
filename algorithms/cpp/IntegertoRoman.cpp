// Source:  https://leetcode-cn.com/problems/integer-to-roman/description/
// Author:  Lianfeng Shen
// Date:    2018-08-30

class Solution {
public:
    string intToRoman(int num) {
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string res;
        for (int i=0; num!=0; i++) {
            while (num >= value[i]) {
                res += symbol[i];
                num -= value[i];
            }
        }
        return res;
    }
};
