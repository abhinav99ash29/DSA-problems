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
    void dfs(TreeNode* root, vector<bool>& del, map<TreeNode*, bool>& arr) {
        if (!root) return;
        arr[root] = true;
        dfs(root->left,del,arr);
        dfs(root->right,del,arr);
        if (root->left && del[root->left->val]) {
            root->left = nullptr;
            arr[root->left] = false;
        }
        if (root->right && del[root->right->val]) {
            root->right = nullptr;
            arr[root->right] = false;
        }
        
        if (del[root->val]) {
            arr[root] = false;
        } else {
            if (root->left) arr[root->left] = false;
            if (root->right) arr[root->right] = false;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        map<TreeNode*, bool> arr;
        vector<bool> del(1001,false);
        for(int& i: to_delete) {
            del[i] = true;
        }
        dfs(root,del,arr);
        vector<TreeNode*> sol;
        for(auto& itr: arr) {
            if (itr.second) {
                sol.push_back(itr.first);
            }
        }
        return sol;
    }
};
