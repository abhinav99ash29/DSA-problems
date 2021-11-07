#include <bits/stdc++.h>
using namespace std;

int main() {
	long int t;scanf("%ld", &t);
	while(t--) {
	    long int n;scanf("%ld", &n);
	    if(n==1) 
	        printf("%d\n", 1);
	    else if(n==2)
	        printf("%d\n", 1);
	   else if(n==3)
	        printf("%d\n", 3);
	   else {
	       long long int sum = ((n-3)*4 + (n-3)*(n-4))+3;
	       printf("%lld\n", sum);
	   }
	}
	return 0;
}
