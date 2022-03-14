class Solution {
    
public:
    int inorder(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int ans;
        while(root!=NULL || !st.empty()) {
            while(root != NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            k--;
            if (k==0) return root->val;
            root = root->right;
        }
        return -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
