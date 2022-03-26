class Solution {
    vector<int> dp;
public:
    
    int fn(vector<int>& coins, int amt) {
        
        if (amt<0) return INT_MAX;
        
        if (amt==0) return 0;
        
        if (dp[amt] != -1) return dp[amt];
        
        int n = coins.size();
        int minC = INT_MAX;
        for(int i=0;i<n;i++) {
            int temp = fn(coins, amt-coins[i]);
            if (temp != INT_MAX)
                minC = min(minC, temp+1);
        }
        return dp[amt] = minC;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, -1);
        int ans = fn(coins, amount);
        return ans == INT_MAX ? -1: ans;
    }
};
