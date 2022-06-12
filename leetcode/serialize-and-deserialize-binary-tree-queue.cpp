/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    TreeNode* root1;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "x";
        return to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right);
    }
    
    TreeNode* helper(queue<string>& q) {
        if (q.empty()) return nullptr;
        string val = q.front();
        q.pop();
        if (val == "x") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = helper(q);
        root->right = helper(q);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string val = "";
        int i = 0;
        for(;i<data.size();i++) {
            if (data[i] == ' ') {
                q.push(val);
                val = "";
            }
            else
            val+=data[i];
        }
        return helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
