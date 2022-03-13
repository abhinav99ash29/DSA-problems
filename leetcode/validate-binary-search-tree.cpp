class Solution {
public:
    bool isValidBST(TreeNode* root, long int mn = (long)INT_MIN-1, long int mx = (long)INT_MAX+1) {
        if(root==NULL) return true;
        if(root->val < mx && root->val > mn) 
            return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
        return false;
    }
};
