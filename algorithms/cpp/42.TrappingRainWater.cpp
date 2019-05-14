// Source :  https://leetcode-cn.com/problems/trapping-rain-water/
// Author :  Lianfeng Shen
// Date   :  2019-05-15

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        
        int res = 0, lmax = 0;
        stack<int> s;
        
        for (int i=0; i < height.size(); s.push(height[i++])) {
            int h = height[i];
            
            if (s.empty()) {
                lmax = h;
            } else if (h >= lmax) {
                while (!s.empty()) {
                    res += lmax - s.top();
                    s.pop();
                }
                lmax = h;
            }
        }
        
        int rmax = s.top(); s.pop();
        while (!s.empty()) {
            if (s.top() < rmax) {
                res += rmax - s.top();
            } else {
                rmax = s.top();
            }
            s.pop();
        }
        return res;
    }
};