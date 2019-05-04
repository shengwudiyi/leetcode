// Source:  https://leetcode-cn.com/problems/regular-expression-matching/
// Author:  Lianfeng Shen
// Date:    2019-05-04

// dp
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[p.size()+1][s.size()+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        
        for(int i=0; i < p.size(); i++) {
            dp[i+1][0] = p[i] == '*' && dp[i-1][0];
        }
        
        for(int i=0; i < p.size(); i++) {
            for(int j=0; j < s.size(); j++) {
                if(p[i] == '*') {
                    if(s[j] == p[i-1] || p[i-1] == '.') {
                        dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j] || dp[i-1][j+1];
                    } else {
                        dp[i+1][j+1] = dp[i-1][j+1];
                    }
                } else {
                    dp[i+1][j+1] = dp[i][j] && (p[i] == '.' || p[i] == s[j]);
                }
            }
        }
        
        return dp[p.size()][s.size()];
    }
};

// backtracking
class Solution {
public:
    bool isMatch(string s, string p) {
        if(!s.size() && !p.size()) return true;
        if(!p.size()) return false;
        if(!s.size()) return p.size() > 1 && p[1] == '*' && isMatch(s, p.substr(2));
        
        if(p.size() > 1 && p[1] == '*') {
            int f = 0;
            do {
                if (isMatch(s.substr(f++), p.substr(2)))
                    return true;
            } while(f <= s.size() && (p[0] == '.' || p[0] == s[f-1])); return false;
        } else {
            return (p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p.substr(1));
        }
    }
};