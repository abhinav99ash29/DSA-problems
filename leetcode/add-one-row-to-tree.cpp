class Solution {
public:
    
    TreeNode* fn(TreeNode* root, int val, int depth, int curr) {
        if (!root) return root;
        if (curr == depth) {
            TreeNode* node1 = new TreeNode(val);
            TreeNode* node2 = new TreeNode(val);
            
            node1->left = root->left;
            node2->right = root->right;
            
            root->left = node1;
            root->right = node2;
            
            return root;
        }
        root->left = fn(root->left,val,depth,curr+1);
        root->right = fn(root->right,val,depth,curr+1);
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        return fn(root,val,depth-1,1);
    }
};
