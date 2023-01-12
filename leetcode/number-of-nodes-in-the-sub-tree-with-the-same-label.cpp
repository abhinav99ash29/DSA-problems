class Solution {
public:

    void dfs(int i, vector<vector<int>>& adj, vector<int>& m, vector<int>& ans,
    string& labels) {
        if (ans[i]==0) {
            ans[i] = 1;
            for(int k=0;k<adj[i].size();k++) {
                int x = adj[i][k];
                vector<int> m1(26,0);
                dfs(x, adj, m1, ans, labels);
                for(int i=0;i<26;i++) {
                    m[i]+=m1[i];
                }
            }
            ans[i]+=m[labels[i]-'a'];
            m[labels[i]-'a']++;
        }
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> m(26,0);
        vector<int> ans(n,0);
        dfs(0, adj, m, ans, labels);
        return ans;
    }
};
