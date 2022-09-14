class Solution {
public:
    
    void dfs(TreeNode* root, int& sol, int parity) {
        if (!root) return;
        parity = parity ^ (1<<root->val); // parity integers bits are used to keep track if a digit has occured odd or even times
        if (!root->left && !root->right) {
            if ((parity & (parity-1)) == 0) sol++; // check if parity is power of 2 denoting atmost 1 number has odd occurence (condition for palindrome atmost 1 odd occurence)
            return;
        }
        dfs(root->left,sol,parity);
        dfs(root->right,sol,parity);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int sol = 0;
        int parity = 0;
        dfs(root,sol,parity);
        return sol;
    }
};
