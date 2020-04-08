// Source : https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/
// Author : Lianfeng Shen
// Date   : 2020-04-09

func longestSubsequence(arr []int, difference int) int {
    var (
        d = map[int]int{}
        r = 0
    )
    for _, v := range arr {
        d[v] = d[v-difference]+1
        if d[v] > r {
            r = d[v]
        }
    }
    return r
}