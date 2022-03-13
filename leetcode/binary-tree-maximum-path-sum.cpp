class Solution {
    int ans=INT_MIN;
public:
    
    int fn(TreeNode* root) {
        if (root == NULL) return 0;
        
        int left = fn(root->left);
        int right = fn(root->right);
        ans = max(ans, root->val);
        ans = max(ans, root->val+left);
        ans = max(ans, root->val+right);
        ans = max(ans, root->val+left+right);
        
        return max(root->val, max(root->val+left, root->val+right));
    }
    
    
    int maxPathSum(TreeNode* root) {
        fn(root);
        return ans;
    }
};
