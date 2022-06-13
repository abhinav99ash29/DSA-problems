class Solution {
public:
    
    int fn(int i, int p, int n) {
        if (i==n) return 0;
        int ans = 1005;
        if ((i+i)<=n)
            ans = fn(i+i,i,n)+2;
        if ((i+p)<=n) {
            ans = min(ans, 1+fn(i+p,p,n));
        }
        return ans;
    }
    
    int minSteps(int n) {
        if (n==1) return 0;
        return fn(2,1,n)+2;
    }
};
