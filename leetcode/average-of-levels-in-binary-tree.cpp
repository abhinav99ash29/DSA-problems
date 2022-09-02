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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sol;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        double sum=0;
        int cnt = 0;
        while(q.size()>1) {
            TreeNode* node = q.front(); q.pop();
            if (!node) {
                q.push(node);
                sol.push_back((double)sum/cnt);
                sum = 0;
                cnt = 0;
                continue;
            }
            sum+=node->val;
            cnt++;
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        sol.push_back((double)sum/cnt);
        return sol;
    }
};
