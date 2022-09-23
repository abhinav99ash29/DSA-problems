class Solution {
public:
    
    int concatenatedBinary(int n) {
        long ans = 1;
        int len = 1;
        for(int i=2;i<=n;i++) {
            if(!(i&(i-1))) ++len;
            ans = (ans<<len)%1000000007 + i;
        }
        return ans%1000000007;
    }
};
