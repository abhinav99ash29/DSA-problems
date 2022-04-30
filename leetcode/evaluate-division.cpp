class Solution {
public:
    double dfs(string &v, string &des, map<string, vector<pair<string, double>>> &adj, map<string, bool> &vis) {
        vis[v] = true;
        if (v==des) {
            return 1;
        }
        double ans = -1;
        for(int i=0;i<adj[v].size();i++) {
            string u = adj[v][i].first;
            double dist = adj[v][i].second;
        
            if (!vis[u]) {
                double temp = dfs(u, des, adj, vis);
                if (temp != -1)
                    ans = dist * temp;
            }
        }
        return ans;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        for(int i=0;i<equations.size();i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], (double)(1/values[i])});
        }
        vector<double> sol;
        for(int i=0;i<queries.size();i++) {
            if (adj.find(queries[i][0])!=adj.end() && adj.find(queries[i][1])!=adj.end()) {
                map<string, bool> vis;
                double ans = dfs(queries[i][0], queries[i][1], adj, vis);
                sol.push_back(ans);
            } else {
                sol.push_back(-1);
            }   
        }
        return sol;
    }
};
