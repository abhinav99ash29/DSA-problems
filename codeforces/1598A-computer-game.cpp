// https://codeforces.com/problemset/problem/1598/A
#include <bits/stdc++.h>
using namespace std;

bool ans=false;

int x[] = {1, -1, 0, 0, 1, -1, -1, 1};
int y[] = {0, 0, 1, -1, -1, 1, -1, 1};

void dfs(int i, int j, vector<string> a, vector<vector<bool>> &vis) {
    vis[i][j] = true;
    int n=a[0].size();
    // cout<<n<<endl;
    if(i==1&&j==(n-1))
        ans=true;
    for(int k=0;k<8;k++) {
        int i1 = i+x[k];
        int j1 = j+y[k];
        
        if(i1<2&&i1>=0&&j1<n&&j1>=0) {
            if(!vis[i1][j1] && !ans && a[i1][j1]!='1') {
                dfs(i1,j1,a,vis);
            }
        }
    }
}

int main() {
	int t; cin>>t;
	while(t--) {
	    ans=false;
	    int n;cin>>n;
	    vector<string>a(2);
	    for(int i=0;i<2;i++) {
	        cin>>a[i];
	    }
	   
	   vector<vector<bool>> vis(2, vector<bool>(n, false));
	   dfs(0, 0, a, vis);
	   
	   if(ans)
	   cout<<"YES"<<endl;
	   else
	   cout<<"NO"<<endl;
	   
	    
	}
	return 0;
}
