class Solution {
    vector<vector<int>> dp;
public:

    int fn(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        if (i==n-1) return grid[i][j];
        if (dp[i][j]!=-1) return dp[i][j];
        int temp = fn(grid,i+1,j);
        if (j>0)
        temp = min(temp, fn(grid,i+1,j-1));
        if (j<n-1)
        temp = min(temp, fn(grid,i+1,j+1));

        return dp[i][j] = grid[i][j]+temp;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) {
            ans = min(ans, fn(grid,0,i));
        }
        return ans;
    }
};
