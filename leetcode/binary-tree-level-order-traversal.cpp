class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int i = 0;
        while(!q.empty()) {
            int sz = q.size();
            if (sz!=0) ans.push_back({});
            while(sz--) {
                TreeNode* tmp = q.front();
                q.pop();
                ans[i].push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            i++;
        }
        return ans;
    }
};
