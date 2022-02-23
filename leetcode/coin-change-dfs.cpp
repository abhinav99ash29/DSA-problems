class Solution {
public:
    int fn(vector<int>& coins, int amount, vector<int>& dp, int MAX) {
        
        if (amount == 0) {
            return 0;
        }
        
        if (dp[amount]!=-1) {
            return dp[amount];
        }
        
        int mn = MAX;
        for(int i=0;i<coins.size();i++) {
            if (amount >= coins[i]) {
                int sub = fn(coins, amount-coins[i], dp, MAX);
                mn = min(mn, 1+sub);
            }   
        }
        return dp[amount] = mn;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = fn(coins, amount, dp, amount+1);
        return ans == amount+1 ? -1 : ans;
    }
};
