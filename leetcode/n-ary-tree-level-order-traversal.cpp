/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> sol;
        queue<Node*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            sol.push_back({});
            while(sz--) {
                Node* node = q.front(); q.pop();
                sol[level].push_back(node->val);
                for(int i=0;i<node->children.size();i++) {
                    if (node->children[i]) q.push(node->children[i]);
                }
            }
            level++;
        }
        return sol;
    }
};
