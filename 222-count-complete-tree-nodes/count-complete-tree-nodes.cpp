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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int leftHeight = findHeightl(root);
        int rightHeight = findHeightr(root);

        if(leftHeight == rightHeight){
            return (1<<leftHeight) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);

        
    }
    int findHeightl(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    int findHeightr(TreeNode* node){
        int height = 0 ;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }    

};