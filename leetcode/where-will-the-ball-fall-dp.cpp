class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> sol(n,-1);
        vector<vector<int>> dp(m+1, vector<int>(n,-1));
        for(int i=m;i>=0;i--) {
            for(int j=0;j<n;j++) {
                if (i==m) {
                    dp[i][j] = j;
                    continue;
                }
                int nj = j+grid[i][j];
                if (nj<0 || nj>n-1 || grid[i][j]!=grid[i][nj]) {
                    dp[i][j] = -1;
                } else {
                    dp[i][j] = dp[i+1][nj];
                }
                if (i==0) {
                    sol[j] = dp[i][j];
                }
            }
        }
        return sol;
    }
};
