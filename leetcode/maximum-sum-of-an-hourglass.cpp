class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int mx = INT_MIN;
        
        for(int i=0;i<=m-3;i++) {
            for(int j=0;j<=n-3;j++) {
                int sum = 0;
                sum = grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]+grid[i+1][j+1];
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};
