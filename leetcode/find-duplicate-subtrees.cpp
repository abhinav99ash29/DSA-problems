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
    unordered_map<string, vector<TreeNode*>> m;
public:
    string in(TreeNode* root) {
        if (!root) return "";
        string str = "("+in(root->left)+to_string(root->val)+in(root->right)+")";
        m[str].push_back(root);
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        in(root);
        vector<TreeNode*> ans;
        for(auto& it: m) {
            if (it.second.size()>1) {
                ans.push_back(it.second[0]);
            }
        }
        return ans;
    }
};
