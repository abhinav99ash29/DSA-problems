class Solution {
public:
    int m, n, ans;
    vector<int> x, y;
    
    void dfs(int i, int j, vector<vector<int>> &grid, int empty) {
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j] < 0) return;
        if (grid[i][j] == 2) {
            if (empty == 0) {
                ans++;
            }
            return;
        }
        int tmp = grid[i][j];
        empty--;
        grid[i][j] = -2; // to create visited block
        for(int k=0;k<4;k++) {
            dfs(i+x[k], j+y[k], grid, empty);
        }
        grid[i][j] = tmp;
        empty++;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ans = 0;
        x = {0, 0, 1, -1};
        y = {1, -1, 0, 0};
        int empty = 1,a,b;
        for(int i=0;i<m;i++) {
           for(int j=0;j<n;j++) {
                if (grid[i][j] == 0) {
                    empty++;
                }
               if (grid[i][j] == 1) {
                   a = i;
                   b = j;
               }
            } 
        }
        dfs(a, b, grid, empty);
        return ans;
    }
};
