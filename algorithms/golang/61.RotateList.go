// Source : https://leetcode-cn.com/problems/rotate-list/
// Author : Lianfeng Shen
// Date   : 2019-05-17

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || k == 0 {
		return head
	}

	var p *ListNode = head
	var l = 1

	for p.Next != nil {
		p = p.Next
		l++
	}

	k = l - k%l
	p.Next = head

	for ; k > 0; k-- {
		p = p.Next
	}
	head, p.Next = p.Next, nil

	return head
}