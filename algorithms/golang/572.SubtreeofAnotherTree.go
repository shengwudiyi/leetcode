// Source : https://leetcode-cn.com/problems/subtree-of-another-tree/
// Author : Lianfeng Shen
// Date   : 2019-06-04

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubtree(s *TreeNode, t *TreeNode) bool {
	if s == nil {
		return t == nil
	} else {
		return isSametree(s, t) || isSubtree(s.Left, t) || isSubtree(s.Right, t)
	}
}

func isSametree(m *TreeNode, n *TreeNode) bool {
	if m == nil && n == nil {
		return true
	} else if m == nil || n == nil {
		return false
	} else {
		return m.Val == n.Val && isSametree(m.Left, n.Left) && isSametree(m.Right, n.Right)
	}
}