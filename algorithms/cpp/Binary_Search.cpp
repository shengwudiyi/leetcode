// Source:  https://leetcode-cn.com/problems/binary-search/description/
// Author:  Lianfeng Shen
// Date:    2018-08-20

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            if (nums[mid] > target) right = mid - 1;
        }
        return -1;
    }
};
