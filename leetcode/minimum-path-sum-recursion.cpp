class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int fn(int i, int j, vector<vector<int>>& grid) {
        if (i<0 || j<0) return INT_MAX;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (i==0 && j==0) return dp[i][j] = grid[0][0];
        
        if (i==0) return dp[i][j] = grid[i][j] + fn(i, j-1, grid);
        
        if (j==0) return dp[i][j] = grid[i][j] + fn(i-1, j, grid);
        
        return dp[i][j] = grid[i][j] + min(fn(i-1,j,grid), fn(i,j-1,grid));
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        return fn(m-1,n-1, grid);
        
    }
};
