#include <bits/stdc++.h>
using namespace std;

void topo_sort_util(int v, vector<bool> &vis, vector<vector<int>> adj, stack<int> &st) {
    vis[v] = true;
    for(auto it=adj[v].begin(); it!=adj[v].end();it++) {
        if(!vis[*it])
        topo_sort_util(*it, vis, adj, st);
    }
    st.push(v);
}

stack<int> topo_sort(int n ,vector<vector<int>> adj) {
    stack<int> st; vector<bool> vis;
    fill(vis.begin(), vis.end(), false);
    for(int i=0;i<n;i++) {
        topo_sort_util(i,vis,adj,st);
    }
    
    return st;
}

int main() {
	// your code goes here
	return 0;
}
