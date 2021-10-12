#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--) {
	    long int n; cin>>n;
	    int orig=n;
	    int a,b;cin>>a>>b;
	    int oc=0,ec=0, ans=0;
        while(n%2==0) {
            if(a>0)
                ans+=a;
            ec++;
            n/=2;
        }
        for(int i=3;i<=sqrt(n);i+=2) {
            while (n % i == 0)
                {
                    oc++;
                    if(b>0)
                        ans+=b;
                    n = n/i;
                }
        }
        if(n>2){
            oc++;
            if(b>0)
                ans+=b;
            n=1;
        }
        if(a<0&&ec>0)
            ans+=a;
        if(b<0&&ec==0)
            ans+=b;
        if(a<0&&b<0&&ec>0&&oc>0)
            ans=max(ans, orig%2==0 ? a : b);
        cout<<ans<<endl;
	}
	return 0;
}
