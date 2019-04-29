// Source : https://leetcode-cn.com/problems/majority-element/
// Author : Lianfeng Shen
// Date   : 2019-04-28

func majorityElement(nums []int) int {
	count := 0
	var curNum int

	for _, num := range nums {
		if count == 0 {
			curNum = num
		}

		if curNum == num {
			count++
		} else {
			count--
		}
	}
	return curNum
}