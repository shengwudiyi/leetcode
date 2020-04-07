// Source : https://leetcode-cn.com/problems/decode-ways/
// Author : Lianfeng Shen
// Date   : 2020-04-07

func numDecodings(s string) int {
    dp := make([]int, len(s))
    if s[0] != '0' {
        dp[0] = 1
    }
    for i := 1; i < len(s); i++ {
        if s[i] != '0' {
            dp[i] += dp[i-1]
        }
        if s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6' {
            if i-2 >= 0 {
                dp[i] += dp[i-2]
            } else {
                dp[i] += 1
            }
        }
    }
    return dp[len(s)-1]
}