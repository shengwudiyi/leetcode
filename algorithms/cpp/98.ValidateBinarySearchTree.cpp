// Source : https://leetcode-cn.com/problems/validate-binary-search-tree/
// Author : Lianfeng Shen
// Date   : 2019-05-07

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        vector<TreeNode*> stack;
        vector<int> vals;
        TreeNode* node = root;
        
        while (stack.size() > 0 || node != NULL) {
            if (node) {
                stack.push_back(node);
                node = node->left;
            } else {
                node = stack.back(); stack.pop_back();
                vals.push_back(node->val);
                node = node->right;
            }
        }
        
        for(int i=0; i < vals.size()-1; i++) {
            if (vals[i+1] <= vals[i]) return false;
        }
        
        return true;
    }
};