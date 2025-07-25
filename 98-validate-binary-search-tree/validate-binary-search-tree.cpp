/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* node, long min_val, long max_val) {
        
        if (node == nullptr) {
            return true;
        }
        
        
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }
        
        
        return helper(node->left, min_val, node->val) && helper(node->right, node->val, max_val);
    }
};