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
    long long int ans = INT_MIN;
    int mod = (int)1e9+7;
    long long int tot = 0;

    void fn1(TreeNode* root) {
        if (!root) return;
        tot+=root->val;
        fn1(root->left);
        fn1(root->right);
    }

    int fn(TreeNode* root) {
        if (!root) return 0;
        int l = fn(root->left);
        int r = fn(root->right);
        ans = max({ans, (long long int)(tot-r)*r, (long long int)(tot-l)*l});
        return root->val + l + r;
    }

public:
    int maxProduct(TreeNode* root) {
        fn1(root);
        fn(root);
        return ans%mod;
    }
};
