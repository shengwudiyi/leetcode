// Source : https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    }
};