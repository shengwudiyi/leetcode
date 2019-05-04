// Source:  https://leetcode-cn.com/problems/largest-divisible-subset/
// Author:  Lianfeng Shen
// Date:    2019-05-04

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        vector<int> dp(size, 1);
        vector<int> solution(size, -1);
        vector<int> ret;
        int ans = 0;
        
        if(size == 0) return ret;
        
        for(int i=0; i < size; i++) {
            for(int j=0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1, solution[i] = j;
                }
            }
            
            if (dp[i] > dp[ans]) ans = i;
        }
        
        for(int i = ans; i != -1; i = solution[i]) {
            ret.push_back(nums[i]);
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};