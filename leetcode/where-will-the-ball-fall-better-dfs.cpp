class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (x==grid.size()) return y;
        int ny = y+grid[x][y];
        if (ny<0 || ny>grid[0].size()-1 || grid[x][y]!=grid[x][ny]) return -1;
        return dfs(x+1,ny,grid);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> sol;
        for(int i=0;i<n;i++) {
            sol.push_back(dfs(0,i,grid));
        }
        return sol;
    }
};
