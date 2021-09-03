#include<bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &parent) {
    int ox = x;
    while(x!=parent[x]){
        x = parent[x];
    }
    parent[ox] = x;
    return x;
}

void union1(int x, int y, vector<int> &parent, vector<int> &sz) {
    int xpar = find(x, parent);
    int ypar = find(y, parent);
    
    if(xpar != ypar) {
        if (sz[xpar] >= sz[ypar]) {
            sz[xpar]+=sz[ypar];
            parent[ypar] = xpar;
        } else {
            sz[ypar]+=sz[xpar];
            parent[xpar] = ypar;
        }
    }
}


int main() {
    int n,q;cin>>n>>q;
    vector<int> parent(n), sz(n);
    for(int i=0;i<n;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    while(q--) {
        char c; 
        cin>>c;
        if(c == 'M') {
            int x, y;
            cin>>x>>y;
            union1(x, y, parent, sz);
        } else {
            int x; cin>>x;
            cout<<sz[find(x, parent)]<<endl;
        }
    } 
    return 0;
}
