#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--) {
	    int n,k;cin>>n>>k;
	    vector<int> a(k);
	    for(int i=0;i<k;i++)
	    cin>>a[i];
	    
	    sort(a.begin(), a.end(),greater<int>());
	    int t=0,ans=0;
	    for(int i=0;i<k;i++) {
	        if(t<a[i]) {
	            ans++;
	            t+=n-a[i];
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

// https://codeforces.com/contest/1593/problem/A
