class Solution {
public:
    
    void reverse(vector<TreeNode*>& v) {
        int n = v.size();
        for(int i=0;i<n/2;i++) {
            swap(v[i]->val,v[n-1-i]->val);
        }
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        vector<TreeNode*> v;
        while(q.size()>0) {
            int sz = q.size();
            while(sz--) {
                TreeNode* node = q.front(); q.pop();
                v.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (l%2) reverse(v);
            l++;
            v.clear();
        }
        return root;
    }
};
