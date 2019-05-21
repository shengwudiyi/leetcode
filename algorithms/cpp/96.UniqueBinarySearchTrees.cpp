// Source : https://leetcode-cn.com/problems/unique-binary-search-trees/
// Author : Lianfeng Shen
// Date   : 2019-05-21

class Solution {
public:
    int numTrees(int n) {
        if (n < 2) return 1;
        
        int dp[n+1];
        fill(dp, dp+n+1, 0);
        
        dp[0] = dp[1] = 1;
        
        for (int i=2; i <= n; i++) {
            for (int j=1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        
        return dp[n];
    }
};