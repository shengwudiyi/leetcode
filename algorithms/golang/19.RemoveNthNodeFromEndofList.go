// Source :	https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
// Author :	Lianfeng Shen
// Date   :	2019-04-25

package golang

type ListNode struct {
    Val int
    Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    lead := &ListNode{0, head}
    fast := lead
    slow := lead
    
    for ; n > 0; n-- {
        fast = fast.Next
    }
    
    for fast != nil && fast.Next != nil {
        fast = fast.Next
        slow = slow.Next
    }
    
    slow.Next = slow.Next.Next
    
    return lead.Next
}