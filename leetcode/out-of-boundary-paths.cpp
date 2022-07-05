class Solution {
    int ans = 0;
    vector<int> X, Y;
    int mod = (int)1e9+7;
public:
    int fn(int i, int j, int left, int m, int n, vector<vector<vector<int>>>&dp) {
        // cout<<i<<" "<<j<<" "<<left<<endl;
        if (i>=m || j>=n || i<0 || j<0) {
            return 1;
        }
        if (dp[i][j][left]!=-1) return dp[i][j][left];
        if (left==0) return 0;
        long int cnt = 0;
        for(int k=0;k<4;k++) {
            cnt+=fn(i+X[k],j+Y[k],left-1,m,n,dp)%mod;
            cnt = cnt%mod;
        }
        return dp[i][j][left] = cnt;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        X = {0,0,1,-1};
        Y = {1,-1,0,0};
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return fn(startRow, startColumn, maxMove, m, n, dp)%mod;
        
    }
};
