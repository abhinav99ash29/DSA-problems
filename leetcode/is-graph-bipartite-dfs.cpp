class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, int x, vector<int> &vis, int sign) {
        vis[x] = sign;
        bool ans = true;
        for(int i=0;i<graph[x].size();i++) {
            if (vis[x] == vis[graph[x][i]]) {
                return false;
            } else if (vis[graph[x][i]] == 0) {
                ans = ans && dfs(graph, graph[x][i], vis, sign*-1);
            }
        }
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++) {
           if (!vis[i]) {
               bool temp = dfs(graph, i, vis, 1);
               if (!temp)
                   return false;
           }
        }
        return true;
    }
};
