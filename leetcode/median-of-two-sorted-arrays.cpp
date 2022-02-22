class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        
        if (n1.size() > n2.size()) {
            return findMedianSortedArrays(n2, n1);
        }
        
        int m = n1.size(), n = n2.size();
        
        int st = 0, end = m;
        double ans = 0;
        while(st<=end) {
            int i = (st+end)/2; 
            
            int j = (m+n+1)/2 - i; 
            
            int leftx= i>0 ? n1[i-1] : INT_MIN;
            int rightx = i<m ? n1[i] : INT_MAX;
            int lefty = j>0 ? n2[j-1] : INT_MIN;
            int righty = j<n ? n2[j] : INT_MAX;
            
            if (leftx <= righty && lefty <= rightx) {
                if ( (m+n)%2 != 0) {
                    return (double)max(leftx, lefty);
                } else {
                    return (double)(max(leftx,lefty)+min(rightx,righty))/2;
                }
            } else if(leftx > righty) {
                end = i-1;
            } else if (lefty>rightx) {
                st = i+1;
            }
            
        }
        return 0;
    }
};
