/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* sol;
    bool found;
public:
    
   pair<bool, bool> fn(TreeNode* root, int p, int q) {
       if (!root) return {false, false};
       pair<bool, bool> pr = {false, false};
       
       if (root->val == p) pr.first = true;
       if (root->val == q) pr.second = true;
       
       pair<bool, bool> pr1 = fn(root->left,p,q);
       pair<bool, bool> pr2 = fn(root->right,p,q);
       
       pr.first = pr.first || pr1.first || pr2.first;
       pr.second = pr.second || pr1.second || pr2.second;
       
       if (!found && pr.first && pr.second) {
           found = true;
           sol = root;
       }
       return pr;
   }
    
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fn(root, p->val, q->val);
        return sol;
    }
};
