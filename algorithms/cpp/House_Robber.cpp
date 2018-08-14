// Source:  https://leetcode-cn.com/problems/house-robber/description/
// Author:  Lianfeng Shen
// Date:    2018-08-14

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i=2; i<n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
    return dp[n-1];
    }
};
