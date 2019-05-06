// Source:  https://leetcode-cn.com/problems/house-robber/
// Author:  Lianfeng Shen
// Date:    2019-05-06

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        for (int i=1; i < nums.size(); i++) {
            if (i == 1) 
                nums[i] = max(nums[i-1], nums[i]);
            else 
                nums[i] = max(nums[i-1], nums[i-2] + nums[i]);
        }
        return nums[nums.size() - 1];
    }
};