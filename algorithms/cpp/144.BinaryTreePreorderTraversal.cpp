// Source :  https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
// Author :  Lianfeng Shen
// Date   :  2019-05-10

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        
        return ans;
    }
    void dfs(TreeNode* node, vector<int>& arr) {
        if (!node) return;
        
        arr.push_back(node->val);
        dfs(node->left, arr);
        dfs(node->right, arr);
    }
};

// non recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> stack;
        
        stack.push_back(root);
        while (!stack.empty()) {
            TreeNode* node = stack.back(); stack.pop_back();
            
            if (!node) {
                continue;
            } else {
                ans.push_back(node->val);
                stack.push_back(node->right);
                stack.push_back(node->left);
            }
        }
        
        return ans;
    }
};