// Source:  https://leetcode-cn.com/problems/3sum-closest/description/
// Author:  Lianfeng Shen
// Date:    2018-10-25

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int c = INT_MAX;
        int r = 0;
        int l = nums.size();
        if (l < 3) return 0;
            
        sort(nums.begin(), nums.end());
        
        for(int i=0; i < l -2; i++) {
            int left = i + 1;
            int right = l - 1;
            while(left < right) {
                int h = nums[i] + nums[left] + nums[right];
                if ( h == target)
                    return target;
                else if (h > target) {
                    if (h - target < c) {
                        c = h - target;
                        r = h;
                    }
                    right--;
                }
                else {
                    if (target - h < c) {
                        c = target - h;
                        r = h;
                    }
                    left++;
                }
            }
        }
        return r;
    }
};
