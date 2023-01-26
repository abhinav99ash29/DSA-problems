class Solution {
public:
    int fn(int s, int d, int k, vector<vector<vector<int>>>& graph, vector<vector<int>>& dp) {
        if (s==d) return 0;
        if (k<=-1) return INT_MAX;
        if (dp[s][k]!=-1) return dp[s][k];
        int ans = INT_MAX;
        for(int i=0;i<graph[s].size();i++) {
            int f = fn(graph[s][i][0], d, k-1, graph, dp);
            if (f!=INT_MAX) {
                ans = min(ans, f+graph[s][i][1]);
            }
        }
        return dp[s][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> graph(n);
        vector<vector<int>> dp(n, vector<int>(k+1,-1));
        for(vector<int>& v: flights) {
            graph[v[0]].push_back({v[1], v[2]});
        }
        int ans = fn(src, dst, k, graph, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
