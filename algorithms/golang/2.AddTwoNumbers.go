// Source : https://leetcode-cn.com/problems/add-two-numbers/
// Author : Lianfeng Shen
// Date   : 2019-04-25

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    p    := &ListNode{0, nil}
    head := p
    
    carry := 0
    for l1 != nil || l2 != nil || carry != 0 {
        sum := getValueAndMoveNext(&l1) + getValueAndMoveNext(&l2) + carry
        carry = sum / 10 
        
        p.Next = &ListNode{sum % 10, nil}
        p = p.Next
    }
    
    return head.Next
}

func getValueAndMoveNext(p **ListNode) int {
    val := 0
    if *p != nil {
        val = (*p).Val
        *p  = (*p).Next
    }
    return val
}
