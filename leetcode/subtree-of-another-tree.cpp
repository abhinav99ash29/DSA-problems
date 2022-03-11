class Solution {
public:
    
    bool sameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && sameTree(p->left, q->left) && sameTree(p->right, q->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (!root && !subroot) return true;
        if (!root || !subroot) return false;
        
        bool rt = sameTree(root, subroot);
        bool left = isSubtree(root->left, subroot);
        bool right = isSubtree(root->right, subroot);
        
        return rt || left || right;
    }
};
