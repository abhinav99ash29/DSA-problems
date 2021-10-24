#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> bridge;

void dfs(vector<int> &par, vector<bool> &vis, vector<int> &disc, vector<int> &low, int ver, int tim, vector<vector<int>> adj) {
    
    vis[ver] = true;
    disc[ver] = tim;
    low[ver] = tim;
    
    for(int i=0;i<adj[ver].size();i++) {
        int u = adj[ver][i];
        
        if(!vis[u]) {
            par[u] = ver;
            dfs(par, vis, disc, low, u, tim+1, adj);
            
            
            if(disc[ver]<low[u])
                bridge.push_back(make_pair(ver,u));
            
            else 
            low[ver] = min(low[ver], low[u]);
        }
        
        else if(u != par[ver]) {
            low[ver] = min(low[ver], disc[u]);
        }
    }
}

void findAP(vector<vector<int>> adj, int n) {
    vector<int> par = vector<int>(n); fill(par.begin(), par.end(), -1);
    vector<bool> vis = vector<bool>(n); fill(vis.begin(), vis.end(), false);
    vector<int> disc = vector<int>(n); fill(disc.begin(), disc.end(), INT_MAX);
    vector<int> low = vector<int>(n); fill(low.begin(), low.end(), INT_MAX);
    
    dfs(par, vis, disc, low, 0, 0, adj);
} 

int main() {
	// your code goes here
	
	int n;cin>>n;
	vector<vector<int>> adj = vector<vector<int>>(n);
	
	for(int i=0;i<n;i++) {
	    int ns; cin>>ns;
	    while(ns--) {
	        int x;cin>>x;
	        adj[i].push_back(x);
	    }
	}
	
	findAP(adj, n);
	
	for(int i=0;i<bridge.size();i++) {
	    cout<<bridge[i].first<<" "<<bridge[i].second<<endl;
	}
	
	
	return 0;
}
