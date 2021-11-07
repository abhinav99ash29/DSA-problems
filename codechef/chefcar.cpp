#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--) {
	    long long int n,v;cin>>n>>v;
	    long long int mx = (n*(n-1))/2;
	    long long int mn = 0;
	    if (n>v) {
	        mn = ((n-v)*(n-v+1))/2 - 1 + v;
	        cout<<mx<<' '<<mn<<endl;
	    }
	    else {
	        mn=n-1;
	        cout<<mx<<' '<<mn<<endl;
	    }
	}
	return 0;
}
