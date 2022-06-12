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
    
    pair<TreeNode*, int> fn(string& data, int n) {
        string val = "";
        int i = n;
        for(;i<data.size();i++) {
            if (data[i]==' ') break;
            val+=data[i];
        }
        if (val == "x") return {nullptr, i};
        TreeNode* root = new TreeNode(stoi(val));
        pair<TreeNode*, int> p = {root, i};
        if (i+1 < data.size()) {
            p = fn(data,i+1);
            root->left = p.first;
        }
        if (p.second+1 < data.size()) {
            p = fn(data,p.second+1);
            root->right = p.first;
        }
        return {root, p.second};
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return fn(data,0).first;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
