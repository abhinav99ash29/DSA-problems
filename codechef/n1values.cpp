#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--) {
	    int n;cin>>n; 
	    cout<<1;
	    for(int i=0;i<n;i++) {
	        long long int val = pow(2,i);
	        cout<<" "<<val;
	    }
	    cout<<endl;
	}
	return 0;
}
