// Source :	https://leetcode-cn.com/problems/two-sum/description/
// Author :	Lianfeng Shen
// Date   :	2019-04-25

package main

import "fmt"

func main() {
    fmt.Println(twoSum([]int{2, 7, 11, 15}, 9))
}

func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    for i, num := range nums {
        if j, ok := m[target - num]; ok {
            return []int{j, i}
        } else {
            m[num] = i
        }
    }
    
    return []int{}
}