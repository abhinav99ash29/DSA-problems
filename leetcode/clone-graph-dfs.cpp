class Solution {
public:
    unordered_map<Node*, Node*> M;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(M[node] == nullptr){
            M[node] = new Node(node->val);
            for(int i = 0; i < node->neighbors.size(); i++){
                M[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }
        return M[node];
    }
};
