#include <bits/stdc++.h>
using namespace std;

int find(vector<int> parent, int i) {
    if(parent[i]==i)
    return i;
    return find(parent, parent[i]);
}

int unionFn(vector<int> &sz, vector<int> &parent, int x, int y) {
    int x_root = find(parent, x);
    int y_root = find(parent, y);
    if(sz[x_root]>=sz[y_root]) {
    parent[y_root] = parent[x_root];
    sz[x_root]+=sz[y_root];
    }
    else {
    parent[x_root] = parent[y_root];
    sz[y_root]+=sz[x_root];
    }
}

int main() {
	// your code goes here
	int n;cin>>n;
	vector<int> par = vector<int>(n);
    vector<int> sz = vector<int>(n);
	return 0;
}
