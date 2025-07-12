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
    
    // Checks if there are more elements to iterate
    bool hasNext() {
        return !myStack.empty(); // True if stack is not empty
    }
};

/**
 * How to use the BSTIterator:
 * BSTIterator* obj = new BSTIterator(root);
 * int next_val = obj->next(); // Gets next smallest element
 * bool has_next = obj->hasNext(); // Checks if more elements exist
 */