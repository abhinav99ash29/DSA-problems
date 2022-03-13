class Solution {
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int n, int x, int y) {
        if (n>=preorder.size() || (y-x+1)<=0) return NULL;
        
        int par = preorder[n];
        TreeNode* node = new TreeNode(par);
        
        int parIdx = find(inorder.begin(), inorder.end(), par) - inorder.begin();
        
        node->left = buildTree(preorder, inorder, n+1, x, parIdx-1);
        node->right = buildTree(preorder, inorder, n+1+(parIdx-x), parIdx+1, y);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, 0, inorder.size()-1);
    }
};
