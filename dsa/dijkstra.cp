#include <bits/stdc++.h>
using namespace std;

int ret_min(vector<int> dist, set<int> spt) {
    int min = INT_MAX;
    int idx=0;
    for(int i=0;i<dist.size();i++) {
        if(spt.find(i) == spt.end() && min>dist[i]) {
            min=dist[i]; idx=i;
        }
    }
    return idx;
}

vector<int> djikstra (int n, vector<vector<int>> adj, vector<vector<int>> edge) {
    set<int> spt;
    vector<int> dist;
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[0]=0;
    while(spt.size() != n) {
        int mn = ret_min(dist, spt);
        spt.insert(mn);
        for(auto it=adj[mn].begin();it!=adj[mn];it++) {
            dist[*it] = min(dist[*it], dist[mn]+edge[mn][*it]);
        }
    }
    return dist;
}

int main() {
	// your code goes here
	return 0;
}
