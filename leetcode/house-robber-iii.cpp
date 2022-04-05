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
    unordered_map<TreeNode*, int> mp;
public:
    int fn(TreeNode* root, bool con) {
        if (root == NULL) return 0;
        if (mp.find(root) != mp.end() && con) return mp[root];
        if (con) {
            return mp[root] = max(root->val+fn(root->left, false)+fn(root->right, false),
                      fn(root->left,true)+fn(root->right, true));
        }
        return fn(root->left, true)+fn(root->right, true);
    }
    int rob(TreeNode* root) {
        return fn(root, true);
    }
};
