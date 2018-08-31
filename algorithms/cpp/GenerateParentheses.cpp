// Source:  https://leetcode-cn.com/problems/generate-parentheses/description/
// Author:  Lianfeng Shen
// Date:    2018-08-31

class Solution {
public:
    void backTrack(vector<string>& res, int left, int right, string s) {
        if (left==0 && right==0) {
            res.push_back(s);
            return;
        }
        if (left>0) backTrack(res, left-1, right, s + "(");
        if (right>0 && right>left) backTrack(res, left, right-1, s + ")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        backTrack(result, n, n, s);
        return result;
    }
};
