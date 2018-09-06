// Source:  https://leetcode-cn.com/problems/3sum/description/
// Author:  Lianfeng Shen
// Date:    2018-09-06

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > res;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i] > 0) break;
            int a = nums[i];
            int low = i+1;
            int high = n-1;
            while(low < high) {
                int b = nums[low];
                int c = nums[high];
                if((a+b+c) == 0) {
                    res.push_back({a, b, c});
                    while(low<n && nums[low]==nums[low+1]) low++; low++;
                    while(high>0 && nums[high]==nums[high-1]) high--; high--;
                } else if((a+b+c) > 0) {
                    high--;
                } else {
                    low++;
                }
            }
        }
        return res;
    }
};
