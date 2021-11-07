#include <bits/stdc++.h>
using namespace std;

long int total(vector<int> c1, vector<int> c2) {
    long long int sum = 0;
    int n2 = c2.size();

    for(int i=n2-2;i>=0;i--) {
        c2[i]+=c2[i+1];
    }
    
    for(int i=0;i<n2;i++) {
        sum+=c1[i]*c2[i];
    }
    return sum;
    

}

int main() {
	int t;cin>>t;
	while(t--) {
	    int n;cin>>n;
	    vector<int> c1,c2;
	    for(int i=0;i<n;i++) {
	        if(i%2 == 0) {
	            int x;cin>>x;
	            c1.push_back(x);
	        } else {
	            int x;cin>>x;
	            c2.push_back(x);
	        }
	    }
	    sort(c1.begin(), c1.end(), greater<int>());
	    sort(c2.begin(), c2.end());
	    int n1=c1.size(),n2=c2.size();
	    int i=0,j=0;
	    while(i<n1&&j<n2) {
	        cout<<c1[i]<<" ";
	        i++;
	        cout<<c2[j]<<" ";
	        j++;
	    }
	    while(i<n1) {
	        cout<<c1[i]<<" ";
	        i++;
	    }
	    while(j<n2) {
	        cout<<c2[j]<<" ";
	        j++;
	    }
	    cout<<endl;
	    cout<<total(c1,c2)<<endl;
	    
	}
	return 0;
}
