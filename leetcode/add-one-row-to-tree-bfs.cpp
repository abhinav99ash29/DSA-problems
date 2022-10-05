class Solution {
public:
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
        depth--;
        
        queue<TreeNode*> q;
        q.push(root);
        int l = 1;
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* node = q.front(); q.pop();
                if (l<depth) {
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                } else {
                    TreeNode* node1 = new TreeNode(val);
                    TreeNode* node2 = new TreeNode(val);

                    node1->left = node->left;
                    node2->right = node->right;

                    node->left = node1;
                    node->right = node2;
                }
            }
            l++;
        }
        
        return root;
    }
};
