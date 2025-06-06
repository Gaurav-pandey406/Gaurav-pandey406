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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        
        return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
    }
    
    int height(TreeNode* node) {
        if(node == NULL)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};