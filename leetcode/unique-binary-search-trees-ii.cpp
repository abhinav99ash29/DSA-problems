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
    
    vector<TreeNode*> fn(int l, int r) {
        if (l>r) return {nullptr};
        if (l==r) return {new TreeNode(l)};
        
        vector<TreeNode*> ans;
        for(int i=l;i<=r;i++) {
            vector<TreeNode*> lv = fn(l,i-1);
            vector<TreeNode*> rv = fn(i+1,r);
            for(auto l: lv) {
                for(auto r: rv) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return fn(1,n);
    }
};
