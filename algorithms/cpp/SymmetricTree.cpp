// Source:  https://leetcode-cn.com/problems/symmetric-tree/description/
// Author:  Lianfeng Shen
// Date:    2018-08-31

// recursive
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (p==NULL || q==NULL) return p == q;
        return (p->val == q->val) &&
                isSymmetric(p->left, q->right) &&
                isSymmetric(p->right, q->left);
    }
};

// non recursive