class Solution {
    int mod = (int)1e9+7;
public:
    long long power(long long a, long long b) {
        long long res = 1;
        while(b>0) {
            if (b & 1)
            res = (res * a) % mod;
            b = b>>1;
            a = (a*a)%mod;
        }
        return res;
    }
    
    int concatenatedBinary(int n) {
        int prevD = 0;
        long long sol = 0;
        for(int i=n;i>0;i--) {
            // cout<<sol<<" "<<prevD<<" "<<power(2,prevD)<<endl;
            sol = (sol%mod + (power(2,prevD%mod)*i)%mod)%mod;
            prevD += log2(i)+1;
        }
        return sol%mod;
    }
};
