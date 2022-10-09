class Solution {
public:
    
    bool find(TreeNode* root, int k, unordered_map<int,bool>& mp) {
        if (!root) return false;
        if (mp.count(k-root->val)) return true;
        mp[root->val] = true;
        return find(root->left, k, mp) || find(root->right, k, mp);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, bool> mp;
        return find(root, k, mp);
    }
};
