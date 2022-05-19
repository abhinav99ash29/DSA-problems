class Solution {
public:
    
    bool detectCycle(int n, unordered_map<int, int>& indeg, vector<vector<int>>& adj) {
        queue<int> q;
        int vis=0;
        for(auto i: indeg) {
            if (i.second == 0) {
                q.push(i.first);
            }
        }
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis++;
            for(int i: adj[u]) {
                indeg[i]--;
                if (indeg[i]==0) {
                    q.push(i);
                }
            }
        }
        return n!=vis;
    }
    
    bool canFinish(int n, vector<vector<int>>& preq) {
        unordered_map<int, int> indeg;
        
        vector<vector<int>> adj(n, vector<int>());
        
        for(int i=0;i<n;i++) {
            indeg[i] = 0;
        }
        
        for(vector<int> p: preq) {
            adj[p[0]].push_back(p[1]);
            indeg[p[1]]++;
        }
        
        return !detectCycle(n,indeg,adj);
    }
};
