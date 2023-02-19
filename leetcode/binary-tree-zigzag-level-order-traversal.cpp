class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root)
        q.push(root);
        vector<int> v;
        int l = 0;
        while(q.size()) {
            int sz = q.size();
            cout<<l<<endl;
            while(sz--) {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (l%2) reverse(v.begin(), v.end());
            ans.push_back(v);
            l++;
            v.clear();
        }
        return ans;
    }
};
