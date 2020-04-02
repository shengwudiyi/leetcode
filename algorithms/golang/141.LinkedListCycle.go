// Source : https://leetcode-cn.com/problems/linked-list-cycle/
// Author : Lianfeng Shen
// Date   : 2020-04-03

func hasCycle(head *ListNode) bool {
    if head == nil {
        return false
    }

    slow := head
    fast := head.Next

    for fast != nil && fast.Next != nil {
        if slow == fast {
            return true
        }
        slow = slow.Next
        fast = fast.Next.Next
    }
    return false
}