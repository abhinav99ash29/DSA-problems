#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	vector<int>b(n);
	fill(b.begin(), b.end(), 1);
	for(int i=1;i<n;i++){
	    if(a[i]>=a[i-1])
	        b[i]=b[i-1]+1;
	}
	int mx = *max_element(b.begin(), b.end());
	
	cout<<mx<<endl;
	
	return 0; 
}
