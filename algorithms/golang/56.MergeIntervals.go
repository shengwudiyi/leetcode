// Source : https://leetcode-cn.com/problems/merge-intervals/
// Author : Lianfeng Shen
// Date   : 2019-04-28

func merge(intervals [][]int) [][]int {
    quickSort(&intervals, 0, len(intervals) - 1)
    
    solutions := [][]int{}
    
    for i, curIndex := 0, -1; i < len(intervals); i++ {
        if curIndex > -1 && intervals[i][0] <= solutions[curIndex][1] {
            solutions[curIndex][1] = max(intervals[i][1], solutions[curIndex][1])
        } else {
            solutions = append(solutions, intervals[i])
            curIndex++
        }
    }
    return solutions
}

func max(x int, y int) int {
    if x > y {
        return x
    } else {
        return y
    }
}

func quickSort(intervals *[][]int, p int, r int) {
    if p  >= r {
        return
    }

    q := partition(intervals, p, r)
    quickSort(intervals, p    , q - 1)
    quickSort(intervals, q + 1, r    )
}

func partition(intervals *[][]int, p int, r int) int {
    pivot := (*intervals)[r]
    
    i := p
    for j := p; j < r; j++ {
        if (*intervals)[j][0] < pivot[0] {
            (*intervals)[i], (*intervals)[j] = (*intervals)[j], (*intervals)[i]
            i++
        }
    }
    (*intervals)[i], (*intervals)[r] = (*intervals)[r], (*intervals)[i]

    return i
}
