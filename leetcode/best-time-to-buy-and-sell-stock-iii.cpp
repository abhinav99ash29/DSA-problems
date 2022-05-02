class Solution {
public:
    
    int fn(vector<int> &prices, int idx, int trans, vector<vector<int>> &dp) {
        if (idx == prices.size()) return 0;
        if (trans == 0) return 0;
        
        if (dp[idx][trans]!=-1) return dp[idx][trans];
        
        int ans1 = fn(prices, idx+1, trans, dp);
        
        bool buy = trans%2 == 0;
        
        int ans2 = 0;
        
        if (buy) {
            ans2 = -prices[idx] + fn(prices, idx+1, trans-1, dp);
        } else {
            ans2 = prices[idx] + fn(prices, idx+1, trans-1, dp);
        }
        return dp[idx][trans] = max(ans1, ans2);
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(5, -1));
        return fn(prices, 0, 4, dp);
    }
};
