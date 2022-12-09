/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sol;
public:
    void fn(TreeNode* root, int mn, int mx) {
        if (!root) return;
        sol = max({sol, abs(root->val-mn), abs(root->val-mx)});
        fn(root->left, min(mn, root->val), max(mx, root->val));
        fn(root->right, min(mn, root->val), max(mx, root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        sol = INT_MIN;
        fn(root, root->val, root->val);
        return sol;
    }
};
