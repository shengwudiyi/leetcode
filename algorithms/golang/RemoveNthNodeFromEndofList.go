// Source:	https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
// Authou:	Lianfeng Shen
// Date:	2018-09-26

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head.Next == nil {
		return nil
	}
	pHead := ListNode{0, head}
	pFast := pHead
	pSlow := pHead
	for i := 0; i < n; i++ {
		pFast = pFast.Next
	}
	for pFast.Next != nil {
		pFast = pFast.Next
		pSlow = pSlow.Next
	}
	pSlow.Next = pSlow.Next.Next
	return pHead.Next
}
