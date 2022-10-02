class Solution {
public:
    int fn(int n, int k, int target, vector<vector<int>>& dp) {
        if (target<=0) return 0;
        if(n==1) {
            if (target<=k) return 1;
            else return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target]%1000000007;
        int sol = 0;
        for(int i=1;i<=k;i++) {
            sol = (sol + fn(n-1,k,target-i,dp))%1000000007;
        }
        // cout<<n<<" "<<target<<" "<<sol<<endl;
        return dp[n][target] = sol%1000000007;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
        return fn(n,k,target,dp)%1000000007;
    }
};
