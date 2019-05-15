// Source : https://leetcode-cn.com/problems/container-with-most-water/
// Author : Lianfeng Shen
// Date   : 2019-05-16

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxa = 0;
        
        while (left < right) {
            maxa = max(maxa, (right-left) * min(height[left], height[right]));
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxa;
    }
};