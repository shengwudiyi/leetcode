// Source : https://leetcode-cn.com/problems/unique-paths-ii/
// Author : Lianfeng Shen
// Date   : 2019-05-16

#define ll long long

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for (int i=0; i < obstacleGrid.size(); i++) {
            for (int j=0; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                } else if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = (ll)1;
                } else if (i == 0) {
                    obstacleGrid[i][j] = (ll)obstacleGrid[i][j-1];
                } else if (j == 0) {
                    obstacleGrid[i][j] = (ll)obstacleGrid[i-1][j];
                } else {
                    obstacleGrid[i][j] = (ll)obstacleGrid[i-1][j] + (ll)obstacleGrid[i][j-1];
                }
            }
        }
        
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};