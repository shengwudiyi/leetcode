// Source:  https://leetcode-cn.com/problems/reverse-integer/
// Author:  Lianfeng Shen
// Date:    2019-02-21

class Solution {
public:
    int reverse(int x) {
        const int MIN = 0x80000000, MAX = 0x7FFFFFFF;
        long int r = 0;
        
        while(x != 0){
            r = r * 10 + x % 10;
            x = x / 10;
            
            if(r < MIN || r > MAX) return 0;
        }
        return r;
    }
};
