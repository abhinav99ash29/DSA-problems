class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i=1;i<m;i++) {
            for(int j=0;j<n;j++) {
                int temp = INT_MAX;
                temp = min(temp, grid[i-1][j]);
                if (j>0)
                temp = min(temp, grid[i-1][j-1]);
                if (j<n-1)
                temp = min(temp, grid[i-1][j+1]);
                grid[i][j] += temp;
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        ans = min(ans, grid[m-1][i]);

        return ans;
    }
};
