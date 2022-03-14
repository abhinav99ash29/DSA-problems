class Solution {
    int ans;
public:
    
    void inorder(TreeNode* root, int &k) {
        if (root == NULL) return;
        inorder(root->left, k);
        k--;
        if (k==0) ans = root->val;
        inorder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
