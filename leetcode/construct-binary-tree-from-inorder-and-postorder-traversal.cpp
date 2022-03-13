class Solution {
public:
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int n, int x, int y) {
        if (n<0 || (y-x+1) <= 0 ) return NULL;
        
        int par = postorder[n];
        
        int parIdx = find(inorder.begin(), inorder.end(), par) - inorder.begin();
        
        TreeNode* node = new TreeNode(par);
        
        node->right = buildTree(inorder, postorder, n-1, parIdx+1, y);
        
        node->left = buildTree(inorder, postorder, n-1-(y-parIdx), x, parIdx-1);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return buildTree(inorder, postorder, postorder.size()-1, 0, inorder.size()-1);
        
    }
};
