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
public:
    
    void fn(TreeNode* root, int target, int& curr, vector<int>& path, vector<vector<int>>& res) {
        if (!root) return;
        curr+=root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && curr==target) {
            res.push_back(path);
        }
        if (root->left) {
            fn(root->left, target, curr, path, res);
        }
        if (root->right) {
            fn(root->right, target, curr, path, res);
        }
        curr-=root->val;
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        int curr = 0;
        fn(root, targetSum, curr, path, res);
        return res;
    }
};
