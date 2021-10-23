// https://codeforces.com/problemset/problem/1592/B
#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> a) {
    int n = a.size();
    bool sorted=true;
	    
    for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1])
        sorted = false;
    }
    
    return sorted;
    
}

int main() {
	int t;cin>>t;
	while(t--) {
	    int n,k; cin>>n>>k;
	    vector<int>a(n);
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
        if(isSorted(a))
        cout<<"YES"<<endl;
        else {
            
            if(n>=(2*k)) {
                cout<<"YES"<<endl;
            }
            else {
                vector<int>b(a);
                string res="YES";
                sort(a.begin(), a.end());
                for(int i=(n-k);i<k;i++) {
                    if(a[i] != b[i])
                    res = "NO";
                }
                
                cout<<res<<endl;
            }
            
        }
	    
	}
	return 0; 
}
