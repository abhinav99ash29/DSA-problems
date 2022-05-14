class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> vis(n, false);
        for(int i=0;i<times.size();i++) {
            int u=times[i][0]-1, v=times[i][1]-1, w=times[i][2];
            adj[u].push_back({v,w});
        }
        
        vector<int> ans(n,INT_MAX);
        queue<pair<int, int>> q;
        q.push({k-1,0});
        vis[k-1] = true;
        ans[k-1] = 0;
        while(!q.empty()) {
            int u = q.front().first;
            int w = q.front().second;
            q.pop();
            for(int i=0;i<adj[u].size();i++) {
                int v = adj[u][i].first;
                int w1 = adj[u][i].second;
                if (!vis[v] || ans[v] > w+w1) {
                    vis[v] = true;
                    ans[v] = w+w1;
                    q.push({v,w+w1});
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                return -1;
            }
        }
        
        return *max_element(ans.begin(), ans.end());
    }
        
};
