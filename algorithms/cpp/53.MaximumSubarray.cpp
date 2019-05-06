// Source : https://leetcode-cn.com/problems/maximum-subarray/
// Author : Lianfeng Shen
// Date   : 2019-05-06

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int solution = nums[0];
        for (int i=1; i < nums.size(); i++) {
            nums[i] = max(nums[i], nums[i-1] + nums[i]);
            solution = max(nums[i], solution);
        }
        
        return solution;
    }
};