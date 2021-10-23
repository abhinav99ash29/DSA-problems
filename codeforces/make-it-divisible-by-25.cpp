// https://codeforces.com/contest/1593/problem/B
#include <bits/stdc++.h>
using namespace std;

bool isdiv(char a, char b) {
    if(a=='0'&&b=='0')
    return true;
    
    int i= (int) b-'0';
    i+=((int) a-'0')*10;
    
    if(i%25 == 0)
    return true;
    
    return false;
}

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--) {
	    string s;cin>>s;
	    int n=s.size();
	    int ans=INT_MAX;
	    for(int i=n-1;i>=0;i--) {
	        for(int j=i-1;j>=0;j--) {
	            if(s[j]=='0'&&j>0) {
	               if(isdiv(s[j],s[i])) {
	               ans = min(n-j-2,ans);
	                } 
	            } else if(s[j]!='0') {
	                if(isdiv(s[j],s[i])) {
    	                ans = min(n-j-2,ans);
	                }
	            }
	            
	        }
	    }
	    cout<<ans<<endl;
	    
	}
	return 0;
}
