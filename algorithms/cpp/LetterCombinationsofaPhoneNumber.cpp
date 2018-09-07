// Source:  https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/ 
// Author:  Lianfeng Shen
// Date:    2018-09-07

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            vector<string> res;
            return res;
        }
        vector<string> res;
        char phone[10][4] = {{' ', '\0', '\0', '\0'}, 
                             {'\0', '\0', '\0', '\0'}, 
                             {'a', 'b', 'c', '\0'}, 
                             {'d', 'e', 'f', '\0'},
                             {'g', 'h', 'i', '\0'}, 
                             {'j', 'k', 'l', '\0'}, 
                             {'m', 'n', 'o', '\0'}, 
                             {'p', 'q', 'r', 's'}, 
                             {'t', 'u', 'v', '\0'}, 
                             {'w', 'x', 'y', 'z'}};
        for(auto ch: digits) {
            vector<string> r;
            int d = ch - '0';
            if(res.size() == 0) {
                for (int i=0; i < 4 && phone[d][i] != '\0'; i++) {
                    string s;
                    s += phone[d][i];
                    r.push_back(s);
                }
            } else {
                for(int i=0; i < res.size(); i++) {
                    for(int j=0; j < 4 && phone[d][j] != '\0'; j++) {
                        r.push_back(res[i] + phone[d][j]);
                    }
                }
            }
            res = r;
        }
        return res;
    }
};
