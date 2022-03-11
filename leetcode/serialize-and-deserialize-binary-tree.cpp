class Codec {
public:
    queue<int> ans;
    TreeNode* q2tree() {
        TreeNode* node = new TreeNode(ans.front()); ans.pop();
        if (node->val == -1001) return NULL;
        node->left = q2tree();
        node->right = q2tree();
        return node;
    }
    
    void string2q(string s) {
        int n = s.size();
        int i=0;
        while(i<n) {
            string tmp = "";
            while(s[i]!=' '&&i<n) {
                tmp+=s[i];
                i++;
            }
            if (tmp!="") {
                ans.push(stoi(tmp));
            }
            i++;
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "-1001";
        return to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string2q(data);
        return q2tree();
    }
};
