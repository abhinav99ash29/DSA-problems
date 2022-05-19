class Solution {
    int m, n;
    vector<vector<int>> dp;
public:
    
    int fn(int i, int j, vector<vector<int>>& mat, int prev, vector<vector<int>>& dp) {
        if (i<0||i>=m||j<0||j>=n||mat[i][j]<=prev) return 0;
        if (dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 + max({fn(i+1,j,mat,mat[i][j],dp),
                      fn(i,j+1,mat,mat[i][j],dp),
                      fn(i,j-1,mat,mat[i][j],dp),
                      fn(i-1,j,mat,mat[i][j],dp)});
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        dp.resize(m,vector<int>(n,0));
        int ans = 1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans = max(ans, fn(i,j,matrix,-1,dp));
            }
        }
        return ans;
    }
};
