class Solution {
    int mod;
public:
    
    int fn(int i, int n, vector<int>& dp) {
        if (i>=n) return 1;
        if (dp[i]!=-1) return dp[i];
        int ans = 0;
        ans = fn(i+1,n,dp)%mod;
        ans = (ans%mod + fn(i+2,n,dp)%mod)%mod;
        return dp[i] = ans%mod;
    }
    
    int countHousePlacements(int n) {
        mod = (int)1e9+7;
        vector<int> dp(n+2,-1);
        long long int ans = fn(0,n,dp)%mod;
        ans = (ans*ans)%mod;
        return ans;
    }
};
