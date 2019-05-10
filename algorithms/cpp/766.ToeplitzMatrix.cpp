// Source :  https://leetcode-cn.com/problems/toeplitz-matrix/
// Author :  Lianfeng Shen
// Date   :  2019-05-10

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        IOS;
        for (int i=1; i < matrix.size(); i++) {
            for (int j=1; j < matrix[0].size(); j++) {
                if (matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }
        
        return true;
    }
};