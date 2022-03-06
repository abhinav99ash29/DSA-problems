class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount+1;
        int dp[amount+1];
        dp[0] = 0;
        for(int i=1;i<=amount;i++) {
            int minCnt = Max;
            for(int coin: coins) {
                if (coin <= i) {
                    minCnt = min(minCnt, 1+dp[i-coin]);
                }
                if (minCnt < Max)
                    dp[i] = minCnt;
                else
                    dp[i] = Max;
            }
        }
        return dp[amount] < Max ? dp[amount] : -1;
    }
};
