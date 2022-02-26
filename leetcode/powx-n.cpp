class Solution {
public:
    double myPow(double x, int n, double ans = 1) {
        if (n==0) return ans;
        
        if (abs(n)%2) {
            if (n>0) {
                ans*=x;
            } else {
                ans/=x;
            }
        }
        
        x = x*x;
        n/=2;
        return myPow(x,n,ans);
    }
};
