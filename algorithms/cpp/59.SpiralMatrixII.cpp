// Source : https://leetcode-cn.com/problems/spiral-matrix-ii/
// Author : Lianfeng Shen
// Date   : 2019-05-30

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int cx = 0, cy = -1, nx, ny;
        int val = 1, direction = 0;
        
        while (val <= n*n) {
            while (1) {
                nx = cx + dx[direction];
                ny = cy + dy[direction]; 
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && matrix[nx][ny] == 0) break;
                direction = (direction + 1) % 4;
            }
            
            matrix[nx][ny] = val++;
            
            cx = nx;
            cy = ny;
        }
        
        return matrix;
    }
};