#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void dfs(int v, vector<vector<int>> adj, vector<int> &vis) {
    vis[v] = true;
    for(int i=0;i<adj[v].size();i++) {
        if(!vis[adj[v][i]])
            dfs(adj[v][i],adj,vis);
    }
    st.push(v);
}

void dfs_rev(int v, vector<vector<int>> adj_rev, vector<int> &vis, map<int, vector<int>> &scc, int x) {
    vis[v] = true;
    for(int i=0;i<adj_rev[v].size();i++) {
        if(!vis[adj_rev[v][i]]) {
            scc[x].push_back(adj_rev[v][i]);
            dfs_rev(adj_rev[v][i],adj_rev,vis,scc,x);
        }
    }
}

int main() {
	// your code goes here
	int n;cin>>n;
	int ed;cin>>ed;
	vector<vector<int>> adj = vector<vector<int>>(n);
	vector<vector<int>> adj_rev = vector<vector<int>>(n);
	for(int i=0;i<ed;i++) {
	    int x,y;cin>>x>>y;
	    adj[x].push_back(y);
	    adj_rev[y].push_back(x);
	}
	vector<int> vis = vector<int>(n); fill(vis.begin(), vis.end(), false);
	map<int, vector<int>> scc;
	dfs(0,adj,vis);
	fill(vis.begin(), vis.end(), false);
	while(st.size()>0) {
	    int x = st.top();
	    st.pop();
	    if(!vis[x]) {
	        scc[x].push_back(x);
	        dfs_rev(x, adj_rev, vis, scc, x);
	    }
	}
	for(auto i:scc)
	{   
	    for(int j=0;j<scc[i.first].size();j++) {
	        cout<<scc[i.first][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
