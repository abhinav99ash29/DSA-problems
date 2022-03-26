class Solution {
    vector<int> dp;
public:
    int fn(int n, int st) {
       if (st>n) return 0;
       if (dp[st]!=-1) return dp[st];
       if (st==n) return 1;
       return dp[st] = fn(n,st+1)+fn(n,st+2); 
    }
    int climbStairs(int n) {
        dp.resize(46,-1);
        return fn(n,0);
    }
};
