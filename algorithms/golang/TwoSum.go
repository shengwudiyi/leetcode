// Source	: https://leetcode-cn.com/problems/two-sum/description/
// Author	: Lianfeng Shen
// Date		: 2018-07-23

func twoSum(nums []int, target int) []int {
    num_map := make(map[int]int)
    for i, v := range nums {
        var ok bool
        var j int
        j, ok = num_map[target-v]
        if ok {
            return []int{j, i}
        } else {
            num_map[v] = i
        }
    }
    return nil
}
