class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<times.size();i++) {
            int u=times[i][0]-1, v=times[i][1]-1, w=times[i][2];
            adj[u].push_back({v,w});
        }
        
        vector<int> ans(n,INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0,k-1});

        ans[k-1] = 0;
        while(!q.empty()) {
            int w = q.top().first;
            int u = q.top().second;
            q.pop();
            if (w>ans[u]) continue;
            for(int i=0;i<adj[u].size();i++) {
                int v = adj[u][i].first;
                int w1 = adj[u][i].second;
                if (ans[v] > w+w1) {
                    ans[v] = w+w1;
                    q.push({w+w1,v});
                }
            }
        }
        
        int ans1 = *max_element(ans.begin(), ans.end());
        
        return ans1 == INT_MAX ? -1 : ans1;
    }
        
};
