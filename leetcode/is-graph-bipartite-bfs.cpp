class Solution {
public:
    
    bool bfs(vector<vector<int>>& graph, int x, vector<int> &vis) {
        int n = graph.size();
        queue<pair<int, int>> q;
        q.push({x,1});
        
        while(!q.empty()) {
            
            int v = q.front().first;
            int sign = q.front().second;
            
            q.pop();
            vis[v] = sign;
            for(int i=0;i<graph[v].size();i++) {
                if (vis[graph[v][i]] == vis[v]) {
                    return false;
                } else if (vis[graph[v][i]]==0) {
                    q.push({graph[v][i], -1*sign});
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++) {
           if (!vis[i]) {
               bool temp = bfs(graph, i, vis);
               if (!temp)
                   return false;
           }
        }
        return true;
    }
};
