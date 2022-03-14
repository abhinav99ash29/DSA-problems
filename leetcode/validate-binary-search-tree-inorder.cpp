class Solution {
public:
    
    bool inorder(TreeNode* root, TreeNode* &prev) {
        if (root == NULL) return true;
        
        if (!inorder(root->left, prev)) return false;
        
        if(prev!=NULL && prev->val >= root->val) return false;
        prev = root;
        return inorder(root->right, prev);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
};
