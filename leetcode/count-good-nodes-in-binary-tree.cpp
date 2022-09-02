class Solution {
public:
    int goodNodes(TreeNode* root, int mx = INT_MIN) {
        if (!root) return 0;
        if (root->val >= mx) {
            return 1+goodNodes(root->left, root->val)+goodNodes(root->right,root->val);
        }
        return goodNodes(root->left, mx) + goodNodes(root->right, mx);
    }
};
