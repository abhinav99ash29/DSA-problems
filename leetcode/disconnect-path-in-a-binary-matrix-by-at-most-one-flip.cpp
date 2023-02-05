class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (i==m-1 && j==n-1) return true;
        if (i>=m || j>=n || grid[i][j]==0) return false;
        grid[i][j] = 0;
        return dfs(i+1,j,grid) || dfs(i,j+1,grid);
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(dfs(0,0,grid) == false) return true;
        grid[0][0] = 1;
        return !dfs(0,0,grid);
    }
};
