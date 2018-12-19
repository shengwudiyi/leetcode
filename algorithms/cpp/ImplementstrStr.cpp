// Source:  https://leetcode-cn.com/problems/implement-strstr/description/
// Author:  Lianfeng Shen
// Date:    2018-11-02

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hl = haystack.size();
        int nl = needle.size();

        for(int i=0; i <= hl-nl; i++){
            if(haystack.substr(i, nl) == needle)
                return i;
        }
        return -1;
    }
};
