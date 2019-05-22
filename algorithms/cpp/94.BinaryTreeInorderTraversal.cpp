// Source : https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// Author : Lianfeng Shen
// Date   : 2019-05-22

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        inorderTraversal(root, vals);
        
        return vals;
    }
    
    void inorderTraversal(TreeNode* node, vector<int>& vals) {
        if (!node) return;
        
        inorderTraversal(node->left, vals);
        vals.push_back(node->val);
        inorderTraversal(node->right, vals);
    }
};

// non recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        vector<TreeNode*> stack;
        
        while (root || !stack.empty()) {
            if (root) {
                stack.push_back(root);
                root = root->left;
            } else {
                root = stack.back(); stack.pop_back();
                vals.push_back(root->val);
                root = root->right;
            }
        }
        
        return vals;
    }
};