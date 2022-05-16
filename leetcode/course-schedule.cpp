class Solution {
public:
    
    bool detectCycle(int v, vector<bool>& vis, vector<bool>& grey, vector<bool>& black, vector<vector<int>>& adj) {
        vis[v]=true;
        grey[v] = true;
        
        bool ans = false;
        
        for(int i=0;i<adj[v].size();i++) {
            int x = adj[v][i];
            if (vis[x] && grey[x]) {
                ans = true;
                break;
            } else if (vis[x] && black[x]) {
                continue;
            } else if (!vis[x]) {
                ans = ans || dfs(x,vis,grey,black,adj);
            }
        }
        
        grey[v] = false;
        black[v] = true;
        return ans;
    }
    
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<bool> vis(n, false);
        vector<bool> grey(n, false), black(n, false);
        
        vector<vector<int>> adj(n, vector<int>());
        
        for(vector<int> p: preq) {
            adj[p[0]].push_back(p[1]);
        }
        
        bool ans = true;
        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                ans = ans && !dfs(i,vis,grey,black,adj);
            }
        }
        return ans;
    }
};
