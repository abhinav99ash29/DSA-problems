class Solution {
public:
    
    int fn(int n, vector<int>& dp) {
        if (n==0 || n==1) return 1;

        if (dp[n] != -1)
            return dp[n];
        
        int ans = 0;
        for (int i=1;i<=n;i++) {
            ans+=fn(i-1,dp)*fn(n-i,dp);
        }
        
        return dp[n] = ans;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return fn(n, dp);
    }
};
