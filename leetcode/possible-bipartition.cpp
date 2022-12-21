class Solution {
public:

    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis) {
        for(int& v: adj[i]) {
            if (vis[v] == 0) {
                vis[v] = -1*vis[i];
                if (!dfs(v, adj, vis)) return false;
            } else {
                if (vis[v]==vis[i]) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1, 0);
        for(int i=0;i<dis.size();i++) {
            adj[dis[i][0]].push_back(dis[i][1]);
            adj[dis[i][1]].push_back(dis[i][0]);
        }
        for(int i=1;i<=n;i++) {
            if (vis[i]==0) {
                vis[i] = 1;
                if (!dfs(i, adj, vis)) return false;
            }
        }
        return true;
    }
};
