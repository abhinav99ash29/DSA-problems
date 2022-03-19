class Solution {
    int m;
    int n;
public:
    
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        if (i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j] == '0') return;
        vis[i][j] = true;
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};
