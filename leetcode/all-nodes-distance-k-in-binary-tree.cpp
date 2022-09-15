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
    
    int dis(TreeNode* root, int k, int target, vector<int>& sol) {
        if (!root) return -1;
        if (root->val == target) {
            dfs(root,k,sol);
            return 1;
        }
        int left = dis(root->left,k,target,sol);
        if(left>0) {
            if (left==k) sol.push_back(root->val);
            else if (left<k) dfs(root->right,k-left-1,sol);
            else return -1;
            return left+1;
        }
        int right = dis(root->right,k,target,sol);
        if (right>0) {
            if (right==k) sol.push_back(root->val);
            else if (right<k) dfs(root->left,k-right-1,sol);
            else return -1;
            return right+1;
        }
        return -1;
    }
    
    void dfs(TreeNode* root, int k, vector<int>& sol) {
        if (!root) return;
        if (k==0) sol.push_back(root->val);
        dfs(root->left, k-1,sol);
        dfs(root->right,k-1,sol);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> sol;
        int temp = dis(root,k,target->val,sol);
        cout<<temp<<endl;
        return sol;
    }
};
