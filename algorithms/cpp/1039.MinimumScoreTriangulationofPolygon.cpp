// Source : https://leetcode-cn.com/problems/minimum-score-triangulation-of-polygon/
// Author : Lianfeng Shen
// Date   : 2019-05-15

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int dp[50][50];
        
        fill(dp[0], dp[0] + 50*50, -1);
        
        for (int len=1; len < A.size(); len++) {
            for (int i=0; i < A.size()-len; i++) {
                int j = i + len;
                if (len == 1) {
                    dp[i][j] = 0;
                } else {
                    for (int k=i+1; k < j; k++) {
                        int val =  dp[i][k] + dp[k][j] + A[i]*A[j]*A[k];
                        dp[i][j] = dp[i][j] == -1 ? val : min(dp[i][j], val);
                    }
                }
            }
        }
        
        return dp[0][A.size()-1];
    }
};