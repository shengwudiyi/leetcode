// Source:  https://leetcode-cn.com/problems/interleaving-string/description/
// Author:  Lianfeng Shen
// Date:    2018-10-30

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        vector<vector<int> > dp(s1.length()+1, vector<int>(s2.length()+1));
        dp[0][0] = 1;
        for(int i=0; i <= s1.length(); i++) {
            for (int j=0; j <= s2.length(); j++) {
                if(i > 0 && dp[i-1][j] == 1 && s1[i-1] == s3[i+j-1]) {dp[i][j] = 1; continue;}
                if(j > 0 && dp[i][j-1] == 1 && s2[j-1] == s3[i+j-1]) {dp[i][j] = 1; continue;}
            }
        }
        return dp[s1.length()][s2.length()] == 1;
    }
};

int main() {
    string s1 = "aab";
    string s2 = "abb";
    string s3 = "ababbb";
    cout << Solution().isInterleave(s1, s2, s3) << endl;
    return 0;
}