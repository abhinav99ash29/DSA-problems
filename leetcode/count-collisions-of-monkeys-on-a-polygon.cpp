class Solution {
public:
    int pow2(int n) {
        long long int a = 2;
        long long int ans = 1;
        int mod = (int)1e9+7;
        while(n) {
            if (n%2) {
                ans = (ans%mod * a%mod)%mod;
            }
            a = (a%mod*a%mod)%mod;
            n = n>>1;
        }
        return ans;
    }
    int monkeyMove(int n) {
        int mod = (int)1e9+7;
        return (pow2(n)-2+mod)%mod;
    }
};
