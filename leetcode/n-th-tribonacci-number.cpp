class Solution {
    unordered_map<int, int> dp;
public:
    int tribonacci(int n) {
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        if (dp.count(n)) return dp[n];
        return dp[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};
