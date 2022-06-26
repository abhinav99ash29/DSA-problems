class Solution {
    int mod;
public:
    
    int countHousePlacements(int n) {
        if (n==1) return 4;
        if (n==2) return 9;
        mod = (int)1e9+7;
        long long int a = 2, b = 3, c=0;
        for(int i=3;i<=n;i++) {
            c = (a%mod + b%mod)%mod;
            a = b%mod;
            b = c%mod;
        }
        long long int ans = (c%mod * c%mod)%mod;
        return ans;
    }
};
