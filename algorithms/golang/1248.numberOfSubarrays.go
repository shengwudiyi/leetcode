// Source : https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
// Author : Lianfeng Shen
// Date   : 2020-04-21

func numberOfSubarrays(nums []int, k int) int {
	var (
		res = 0
		c   = 0
		d   = map[int]int{0: 1}
	)
	for _, n := range nums {
		if n%2 == 1 {
			c++
		}
		d[c]++
		res +=d[c-k]
	}
	return res
}
