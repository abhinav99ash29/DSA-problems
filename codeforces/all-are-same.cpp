// https://codeforces.com/contest/1593/problem/D1
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--) {
	    int n;cin>>n;
	    vector<int>a(n);
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    int min=*min_element(a.begin(), a.end());
	    vector<int>diff;
	    for(int i=0;i<n;i++) {
	        if(a[i]-min != 0)
	        diff.push_back(a[i]-min);
	    }
	    
	    int n1=diff.size();
        if(n1 == 0) {
            cout<<-1<<endl;
        } else {
            int result = diff[0];
            for (int i = 1; i < n1; i++)
            {
                result = gcd(diff[i], result);
         
                if(result == 1)
                break;
            }
            cout<<result<<endl;
        }
	}
	return 0;
}
