// Source:  https://leetcode-cn.com/problems/symmetric-tree/description/
// Author:  Lianfeng Shen
// Date:    2018-08-31

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (p==NULL && q==NULL) return true;
        if (p==NULL || q==NULL) return false;
        return (p->val == q->val) &&
                isSymmetric(p->left, q->right) &&
                isSymmetric(p->right, q->left);
    }
};
