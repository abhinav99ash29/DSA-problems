class Solution {
public:
    int dfs(int i, vector<vector<int>>& adj, vector<int>& vis, int seats, long long& fuel) {
        vis[i] = true;
        int cnt = 1;
        for(int&v: adj[i]) {
            if (!vis[v]) {
                cnt+=dfs(v, adj, vis, seats, fuel);
            }
        }
        if (i!=0)
        fuel+=(long long)ceil((float)cnt/seats);
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<vector<int>> adj(n);
        for(vector<int>& v: roads) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(n, false);
        long long fuel = 0;
        dfs(0, adj, vis, seats, fuel);
        return fuel;
    }
};
