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
    
    void preorder(TreeNode* root, int i, int j, map<int, vector<pair<int, int>>>& mp) {
        if (!root) return;
        mp[j].push_back({i,root->val});
        preorder(root->left,i+1,j-1,mp);
        preorder(root->right,i+1,j+1,mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        preorder(root,0,0,mp);
        vector<vector<int>> ans;
        for(auto& itr: mp) {
            vector<pair<int, int>> temp = itr.second;
            sort(temp.begin(), temp.end());
            vector<int> temp1;
            for(pair<int,int>& p: temp) temp1.push_back(p.second);
            ans.push_back(temp1);
        }
        return ans;
    }
};
