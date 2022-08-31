class Solution {
    vector<vector<bool>> vis;
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<pair<bool, bool>>>& oc, bool flag, int prev) {
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]<prev || vis[i][j]) return;
        if (flag) oc[i][j].first = true;
        else oc[i][j].second = true;
        vis[i][j] = true;
        dfs(i+1,j,m,n,grid,oc,flag,grid[i][j]);
        dfs(i-1,j,m,n,grid,oc,flag,grid[i][j]);
        dfs(i,j+1,m,n,grid,oc,flag,grid[i][j]);
        dfs(i,j-1,m,n,grid,oc,flag,grid[i][j]);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vis.resize(m,vector<bool>(n,false));
        vector<vector<pair<bool, bool>>> oc(m, vector<pair<bool, bool>>(n, {false, false}));
        // top edge dfs
        fill(vis.begin(), vis.end(), vector<bool>(n,false));
        for(int j=0;j<n;j++)
            dfs(0,j,m,n,heights,oc,false,INT_MIN);
        // bottom edge dfs
        fill(vis.begin(), vis.end(), vector<bool>(n,false));
        for(int j=0;j<n;j++)
            dfs(m-1,j,m,n,heights,oc,true,INT_MIN);
        // left edge dfs
        fill(vis.begin(), vis.end(), vector<bool>(n,false));
        for(int i=0;i<m;i++)
            dfs(i,0,m,n,heights,oc,false,INT_MIN);
        // right edge dfs
        fill(vis.begin(), vis.end(), vector<bool>(n,false));
        for(int i=0;i<m;i++)
            dfs(i,n-1,m,n,heights,oc,true,INT_MIN);
        vector<vector<int>> sol;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (oc[i][j].first && oc[i][j].second) {
                    sol.push_back({i,j});
                }
            }
        }
        return sol;
    }
};
