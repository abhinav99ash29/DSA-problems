class Solution {
    int ans = INT_MAX;
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
public:
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int t) {
        int n = grid.size();
        if (i==n-1 && j==n-1) return true;
        vis[i][j] = true;
        for(int k=0;k<4;k++) {
            int i1 = i+X[k], j1 = j+Y[k];
            if (i1<0 || j1<0 || i1>=n || j1>=n || vis[i1][j1] || t<grid[i][j] || t<grid[i1][j1]) continue;
            if (dfs(i1,j1,grid,vis,t)) return true;
        }
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0, r = INT_MIN;
        for(int i=0;i<n;i++) {
            r = max(r, *max_element(grid[i].begin(), grid[i].end()));
        }
        
        while(l<=r) {
            int mid = (l+r)/2;
            vector<vector<bool>> vis(n,vector<bool>(n,false));
            if (dfs(0,0,grid,vis,mid)) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
