// Source : https://leetcode-cn.com/problems/longest-palindromic-substring/
// Author : Lianfeng Shen
// Date   : 2019-04-29

// trick
func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}

	indexLeft, indexRight := 0, 0
	for r, i := 0, 0; i < len(s); i, r = r+1, r+1 {
		for r < len(s)-1 && s[r] == s[r+1] {
			r++
		}

		left, right := i, r
		for left-1 > -1 && right+1 < len(s) && s[left-1] == s[right+1] {
			left--
			right++
		}

		if right-left > indexRight-indexLeft {
			indexLeft, indexRight = left, right
		}
	}

	return s[indexLeft : indexRight+1]
}

// dp
func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}

	indexLeft, indexRight := 0, 0

	dp := [1000][1000]bool{}
	for i := 0; i < len(s); i++ {
		dp[i][i] = true
		if i < len(s)-1 && s[i] == s[i+1] {
			dp[i][i+1] = true
			if indexRight-indexLeft+1 < 2 {
				indexLeft, indexRight = i, i+1
			}
		}
	}

	for l := 3; l <= len(s); l++ {
		for i := 0; i+l-1 < len(s); i++ {
			dp[i][i+l-1] = dp[i+1][i+l-2] && s[i] == s[i+l-1]
			if dp[i][i+l-1] {
				if indexRight-indexLeft+1 < l {
					indexLeft, indexRight = i, i+l-1
				}
			}
		}
	}

	return s[indexLeft : indexRight+1]
}