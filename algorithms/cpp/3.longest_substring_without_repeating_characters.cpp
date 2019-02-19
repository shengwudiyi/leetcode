// Source:  https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
// Author:  Lianfeng Shen
// Date:    2019-02-19

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int bitmap[128];
        memset(bitmap, -1, sizeof(bitmap));
        
        int left = 0;
        int maxLen = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(bitmap[s[i]] < left) {
                maxLen = (i - left + 1) > maxLen ? i - left + 1: maxLen;
            } else {
                left = bitmap[s[i]] + 1;
            }
            bitmap[s[i]] = i;
        }
        return maxLen;
    }
};
