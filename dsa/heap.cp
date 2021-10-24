#include <bits/stdc++.h>
using namespace std;

void heapify(int i, int n, vector<int> &a) {
    int l = 2*i;
    int r = 2*i + 1;
    
    int largest = i;
    
    if(l<n&&a[l]>a[i])
        largest = l;
        
    if(r<n&&a[r]>a[largest])
    largest = r;
    
    if(largest != i) {
        swap(a[largest], a[i]);
        heapify(largest, n, a);
    }
}

void build(vector<int> &a) {
    int n = a.size();
    for(int i=n/2;i>=0;i--) {
        heapify(i,n,a);
    }
    
} 

void heap_sort(vector<int> &a) {
    int n = a.size();
    int heap_size=n;
    for(int i=n-1;i>=1;i--) {
        swap(a[0],a[i]);
        heap_size--;
        heapify(0,heap_size,a);
    }
    
}

int main() {
	// your code goes here
	int n;cin>>n; vector<int> a;
	int l = n;
	while(n--) {
	    int x;cin>>x;
	    a.push_back(x);
	}
	
	build(a);
	heap_sort(a);
	for(int i=0;i<l;i++)
	cout<<a[i]<<" ";
return 0;
}
