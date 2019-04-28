// Source : https://leetcode-cn.com/problems/combination-sum/
// Author : Lianfeng Shen
// Date   : 2019-04-27

func combinationSum(candidates []int, target int) [][]int {
    r := [][]int{}

    dfs(&candidates, 0, &[]int{}, target, &r)
    return r
}

func dfs(candidates *[]int, i int, arr *[]int, target int, r *[][]int) {
    if target == 0 {
        *r = append(*r, append([]int{}, *arr...))
    }
    
    if target <= 0 || i == len(*candidates) {
        return
    }
    
    *arr = append(*arr, (*candidates)[i])
    dfs(candidates, i, arr, target - (*candidates)[i], r)
    
    *arr = (*arr)[: len(*arr) - 1]
    dfs(candidates, i+1, arr, target, r)
}
