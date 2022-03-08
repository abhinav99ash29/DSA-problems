class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        if (root->left != NULL) {
            vector<int> l = inorderTraversal(root->left);
            ans.insert(ans.end(), l.begin(), l.end());
        }   
        ans.push_back(root->val);
        if (root->right != NULL) {
            vector<int> r = inorderTraversal(root->right);
            ans.insert(ans.end(), r.begin(), r.end());   
        }
        return ans;
    }
};
