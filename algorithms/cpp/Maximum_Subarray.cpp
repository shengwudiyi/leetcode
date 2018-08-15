// Source:  https://leetcode-cn.com/problems/maximum-subarray/description/
// Author:  Lianfeng Shen
// Date:    2018-08-15

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int dp  = nums[0];
        for(int i=1; i<nums.size(); i++) {
            dp = max(dp+nums[i], nums[i]);
            res = max(res, dp);
        }
        return res;
    }
};
