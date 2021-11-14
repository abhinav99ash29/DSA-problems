// https://www.codechef.com/START15B/problems/MINSZ
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--) {
	    unsigned long long int c; cin>>c;
	    vector<unsigned long long int> ans;
	    unsigned long long int curr_xor = 0;
	    cout.setf(ios::fixed);
	    for(int i=60;i>=0;i--) {
	        unsigned long long int b1 = (1LL << i) & c;
	        unsigned long long int b2 = (1LL << i) & curr_xor;
	        
	        if(b1 != b2) {
	            ans.push_back( (1LL << (i+1)) - 1 );
	            curr_xor ^= ((1LL << (i+1)) - 1);
	        }
	    }
	    if(ans.size() == 0) {
	        ans.push_back(1);
	        ans.push_back(1);
	        
	    }
	    cout<<ans.size()<<endl;
	    for(int i=0;i<ans.size();i++)
	    cout<<setprecision(0)<<ans[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
