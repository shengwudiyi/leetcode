// Source : https://leetcode-cn.com/problems/symmetric-tree/
// Author : Lianfeng Shen
// Date   : 2019-05-22

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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q1; q1.push(root->left);
        queue<TreeNode*> q2; q2.push(root->right);
        
        while (q1.size() && q2.size()) {
            TreeNode* p1 = q1.front(); q1.pop();
            TreeNode* p2 = q2.front(); q2.pop();
            
            if (!p1 && !p2) continue;
            if (!p1 || !p2) return false;
            
            if (p1->val != p2->val) return false;

            q1.push(p1->left); q2.push(p2->right);
            q1.push(p1->right); q2.push(p2->left);
        }
        
        return true;
    }
};