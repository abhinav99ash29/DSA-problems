/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if (node==NULL) return node;
        
        queue<Node*> q;
        q.push(node);
        mp[node->val] = new Node(node->val);
        while(!q.empty()) {
            Node* top = q.front(); q.pop();
            for(int i=0;i<top->neighbors.size();i++) {
                if (mp[top->neighbors[i]->val] == NULL) {
                    mp[top->neighbors[i]->val] = new Node(top->neighbors[i]->val);
                    q.push(top->neighbors[i]);
                }
                mp[top->val]->neighbors.push_back(mp[top->neighbors[i]->val]);
            }
        }
        return mp[node->val];
    }
};
