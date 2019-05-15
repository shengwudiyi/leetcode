// Source : https://leetcode-cn.com/problems/longest-valid-parentheses/
// Author : Lianfeng Shen
// Date   : 2019-05-16

class Solution {
public:
    int longestValidParentheses(string s) {
        
        if (s.size() == 0) return 0;
        
        int maxl = 0;
        int mem[s.size()];
        
        fill(mem, mem + s.size(), 0);
        stack<int> st;
        
        for (int i=0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    mem[st.top()] = 1; mem[i] = 1;
                    st.pop();
                }
            }
        }
        
        int acc = 0;
        for (auto n : mem) {
            if (n == 1) {
                acc++;
            } else {
                maxl = max(maxl, acc);
                acc = 0;
            }
        }
        
        return max(maxl, acc);
    }
};