// Source : https://leetcode-cn.com/problems/minimum-path-sum/
// Author : Lianfeng Shen
// Date   : 2019-04-29

func minPathSum(grid [][]int) int {
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if i == 0 && j == 0 {
				continue
			} else if i == 0 {
				grid[i][j] += grid[i][j-1]
			} else if j == 0 {
				grid[i][j] += grid[i-1][j]
			} else {
				grid[i][j] += min(grid[i-1][j], grid[i][j-1])
			}
		}
	}
	return grid[len(grid)-1][len(grid[0])-1]
}

func min(x int, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}