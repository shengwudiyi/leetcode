// Source : https://leetcode-cn.com/problems/valid-parentheses/
// Author : Lianfeng Shen
// Date   : 2019-05-14

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> pair;
        
        for (auto ch : s) {
            if (ch == ')' || ch == '}' || ch == ']') {
                if (pair.empty()) return false;
                
                if ( (pair.top() == '(' && ch == ')') || (pair.top() == '{' && ch == '}') || (pair.top() == '[' && ch == ']') ) {
                    pair.pop();
                } else {
                    return false;
                }
            } else {
                pair.push(ch);
            }
        }
        
        return pair.empty();
    }
};