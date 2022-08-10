/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* fn(vector<int>& nums, int l, int r) {
        if (l>r) return nullptr; 
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = fn(nums,l,mid-1);
        node->right = fn(nums, mid+1, r);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fn(nums,0,nums.size()-1);
    }
};
