class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        if(root->left)
            invertTree(root->left);
        root->right = temp;
        if(root->right)
            invertTree(root->right);
        
        return root;
        
    }
};
