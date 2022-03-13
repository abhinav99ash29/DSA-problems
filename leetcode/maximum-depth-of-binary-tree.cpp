class Solution {
public:
    int maxDepth(TreeNode* root, int ht = 0) {
        if (root == NULL) return ht;
        return max(maxDepth(root->left,ht+1),maxDepth(root->right,ht+1));
    }
};
