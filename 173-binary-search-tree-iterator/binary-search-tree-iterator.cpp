class BSTIterator {
private:
    stack<TreeNode*> myStack; 

    
    void pushAllLeft(TreeNode* node) {
        while (node != NULL) {
            myStack.push(node);
            node = node->left; 
        }
    }

public:
    
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    
    int next() {
        TreeNode* current = myStack.top();
        myStack.pop(); 
        
        pushAllLeft(current->right);
        
        return current->val; 
    }
    
    
    bool hasNext() {
        return !myStack.empty();
    }
};

