class Solution {
public:
    
    bool fn(TreeNode* root, int target) {
        if (!root) return false;
        if (!root->left && !root->right) return target==root->val;
        if(fn(root->left, target-root->val)) return true;
        if(fn(root->right,target-root->val)) return true;
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fn(root,targetSum);
    }
};
