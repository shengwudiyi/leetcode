// Source:  https://leetcode-cn.com/problems/trapping-rain-water/description/
// Author:  Lianfeng Shen
// Date:    2018-08-24

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int maxHigh = 0;
        int maxHigh_index = -1;
        int prevHigh = 0;
        for (int i=0; i < height.size(); i++){
            if (height[i] > maxHigh) {
                maxHigh = height[i];
                maxHigh_index = i;
            }
        }
        for (int i=0; i < maxHigh_index; i++) {
            if (height[i] > prevHigh) prevHigh = height[i];
            res += prevHigh - height[i];
        }
        prevHigh = 0;
        for (int i = height.size()-1; i > maxHigh_index; i--) {
            if (height[i] > prevHigh) prevHigh = height[i];
            res += prevHigh - height[i];
        }
        return res;
    }
};
static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
