// Source:  https://leetcode-cn.com/problems/contains-duplicate-ii/description/
// Author:  Lianfeng Shen
// Date:    2018-08-01

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n;
        for (int i=0; i<nums.size(); i++) {
            n = nums[i];
            if (m.find(n) != m.end() && i-m[n] <= k) {
                return true;
            }
            m[n] = i;
        }
        return false;
    }   
};
