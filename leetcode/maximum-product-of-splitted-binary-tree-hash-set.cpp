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
    unordered_set<int> st;
public:
    int createSet(TreeNode* root) {
        if (!root) return 0;
        int l = createSet(root->left);
        int r = createSet(root->right);
        st.insert(l+r+root->val);
        return l+r+root->val;
    }

    int maxProduct(TreeNode* root) {
        int tot = createSet(root);
        long long int ans = INT_MIN;
        for(int i: st) {
            ans = max(ans, (long long int)(tot-i)*i);
        }
        return ans%1000000007;
    }
};
