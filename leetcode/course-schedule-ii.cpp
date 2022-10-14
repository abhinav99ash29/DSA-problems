class Solution {
public:
    
    bool checkCycle(int i, vector<vector<int>>& adj, vector<bool>& rec, vector<bool>& vis) {
        vis[i] = true;
        rec[i] = true;
        for(int j=0;j<adj[i].size();j++) {
            if (!vis[adj[i][j]]) {
                if (checkCycle(adj[i][j],adj,rec,vis))
                    return true;
            } else if (rec[adj[i][j]]) {
                return true;
            }
        }
        rec[i] = false;
        return false;
    }
    
    void topo(int i, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[i] = true;
        for(int j=0;j<adj[i].size();j++) {
            if (!vis[adj[i][j]]) {
                topo(adj[i][j],adj,vis,st);
            }
        }
        st.push(i);
    }
    
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>(0));
        vector<bool> rec(n,false);
        vector<bool> vis(n,false);
        for(int i=0;i<pre.size();i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        for(int i=0;i<n;i++) {
            if(!vis[i] && checkCycle(i,adj,rec,vis)) {
                return {};
            }
        }
        fill(vis.begin(), vis.end(), false);
        stack<int> st;
        for(int i=0;i<n;i++) {
            if (!vis[i])
            topo(i,adj,vis,st);
        }
        vector<int> sol;
        while(!st.empty()) {
            sol.push_back(st.top());
            st.pop();
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
