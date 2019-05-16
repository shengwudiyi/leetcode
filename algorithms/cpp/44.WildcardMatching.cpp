// Source : https://leetcode-cn.com/problems/wildcard-matching/
// Author : Lianfeng Shen
// Date   : 2019-05-16

// dp
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size()+1][p.size()+1];
        fill(dp[0], dp[0] + (s.size()+1) * (p.size()+1), false);
        
        for (int i=0; i <= s.size(); i++) {
            for (int j=0; j <= p.size(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j-1] && p[j-1] == '*';
                } else if (j == 0) {
                    dp[i][j] = false;
                } else {
                    dp[i][j] = (dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?')) || ((dp[i][j-1] || dp[i-1][j]) && p[j-1] == '*');
                }
            }
        }
        
        return dp[s.size()][p.size()];
    }
};

// backtracking
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int start = -1;
        int match;
        
        while (i < s.size()) {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                i++; j++;
            } else if (j < p.size() && p[j] == '*') {
                start = j++;
                match = i;
            } else if (start != -1) {
                i = ++match;
                j = start+1;
            } else {
                return false;
            }
        }
        
        while (j < p.size() && p[j] == '*') j++;
        
        return j == p.size();
    }
};