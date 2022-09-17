/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int fill(TreeNode* root, unordered_map<int, int>& m, int target) {
        if (!root) return -1;
        if (root->val == target) return m[root->val] = 0;
        int left = fill(root->left, m, target);
        if (left>=0) return m[root->val] = left+1;
        int right = fill(root->right,m,target);
        if (right>=0) return m[root->val] = right+1;
        return -1;
    }
    
    void dfs(TreeNode* root, int dis, unordered_map<int,int>& m, int& k, vector<int>& sol) {
        if (!root) return;
        if (m.count(root->val)) dis = m[root->val];
        if (dis==k) sol.push_back(root->val);
        dfs(root->left,dis+1,m,k,sol);
        dfs(root->right,dis+1,m,k,sol);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, int> m;
        vector<int> sol;
        fill(root,m,target->val);
        
        dfs(root,0,m,k,sol);
        
        return sol;
        
    }
};
