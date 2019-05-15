// Source : https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
// Author : Lianfeng Shen
// Date   : 2019-05-15

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
    vector<TreeNode*> generateTrees(int n) {
        return n > 0 ? helper(1, n) : vector<TreeNode*>();
    }
    
    vector<TreeNode*> helper(int min, int max) {
        vector<TreeNode*> result;
        
        if (min > max) {
            result.push_back(NULL);
            return result;
        };
        
        for (int i=min; i <= max; i++) {
            vector<TreeNode*> left = helper(min, i-1);
            vector<TreeNode*> right = helper(i+1, max);
            
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
                
        }
        
        return result;
    }
};