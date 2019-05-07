// Source : https://leetcode-cn.com/problems/sort-colors/
// Author : Lianfeng Shen
// Date   : 2019-05-08

func sortColors(nums []int)  {
    i, j := 0, len(nums) - 1
    
    for c := 0; c <= j; c++ {
        if nums[c] == 0 {
            nums[c], nums[i] = nums[i], nums[c]
            i++
        } else if nums[c] == 2 {
            nums[c], nums[j] = nums[j], nums[c]
            j--
            c--
        }
    }
}