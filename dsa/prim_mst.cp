#include <bits/stdc++.h>
using namespace std;

int find_mn(vector<int> key) {
    return distance(key.begin(), min_element(key.begin(),key.end()));
}

vector<int> prim(vector<vector<int>> adj, int n, vector<vector<int>> edge) {
    set<int> mst;
    vector<int> key = vector<int>(n);
    fill(key.begin(), key.end(), INT_MAX);
    key[0] = 0;
    while(mst.size()!=n) {
        int mn = find_mn(key);
        mst.insert(mn);
        for(int i=0;i<adj[mn].size();i++) {
            key[adj[mn][i]] = min(key[adj[mn][i]], edge[mn][adj[mn][i]]);
        }
    }
    return key;
}

int main() {
	// your code goes here
	return 0;
}
