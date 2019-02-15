// Source:  https://leetcode-cn.com/problems/two-sum/
// Author:  Lianfeng Shen
// Date:    2019-02-15

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        
        for(int i=0; i < nums.size(); i++){
            if(m.find(target - nums[i]) !=  m.end()){
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
                break;
            } else {
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};
