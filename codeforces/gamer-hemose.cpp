    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	int t;cin>>t;
    	while(t--) {
    	    int n, h;cin>>n>>h;
    	    vector<int>a(n);
    	    for(int i=0;i<n;i++) {
    	        cin>>a[i];
    	    }
    	    int cnt=0;
    	    sort(a.begin(), a.end(), greater<int>());
    	    int sm1 = a[0];
    	    int sm2 = a[1];
    	    int sm3 = a[0]+a[1];
    	    int res=h;
    	    if(res > sm3) {
    	        cnt += (res/sm3)*2;
    	        int md = res%sm3;
    	        res = md;
    	    }
    	    
    	    if(res>0) {
    	        cnt+=1;
    	        res-=sm1;
    	    }
    	    
    	    if(res>0) {
    	        cnt+=1;
    	        res-=sm2;
    	    }
        
    	    cout<<cnt<<endl;
    	     	     
    	}
    	return 0; 
    }
