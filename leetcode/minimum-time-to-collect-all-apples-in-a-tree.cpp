class Solution {
public:

    int dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& has) {
        vis[i] = true;
        int ans = 0;
        for(int k=0;k<adj[i].size();k++) {
            int x = adj[i][k];
            if (!vis[x]) {
                ans+=dfs(x,adj,vis,has);
            }
        }
        if (ans!=0 && i!=0) ans+=2;
        else if (i!=0) ans+=has[i]*2;
        return ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(int i=0;i<edges.size();i++) {
            vector<int> e = edges[i];
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0,adj,vis,hasApple);
    }
};
