// Source : https://leetcode-cn.com/problems/integer-break/
// Author : Lianfeng Shen
// Date   : 2020-04-07

func integerBreakWithTrick(n int) int {
    if n == 2 {
        return 1
    }
    if n == 3 {
        return 2
    }
    
	product := 1
	for n > 4 {
		product *= 3
		n -= 3
	}
	product *= n
	return product
}

func integerBreakWithDP(n int) int {
    dp := make([]int, n+1)
    for i := 2; i <= n; i++ {
        for j := 1; j <= i/2; j++ {
            dp[i] = max(dp[i], max(j, dp[j])*max(i-j, dp[i-j]))
        }
    }
    return dp[n]
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}