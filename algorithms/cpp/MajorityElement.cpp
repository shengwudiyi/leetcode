// Source:  https://leetcode-cn.com/problems/majority-element/description/
// Author:  Lianfeng Shen
// Date:    2018-09-07

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
