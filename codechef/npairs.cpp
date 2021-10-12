#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--) {
	    int n;cin>>n;
	    vector<char> s(n);
	    for(int i=0;i<n;i++)
	    cin>>s[i];
	    int cnt=0;
	    for(int i=0;i<(n-1);i++) {
	        for(int j=i+1;j<min(n,i+10);j++) {
	           // cout<<int(s[j]-'0')<<" "<<int(s[i]-'0')<<endl;
	            if((j-i) == abs(int(s[j]-'0')-int(s[i]-'0'))) {
	                cnt++;
	            }
	        }
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}
