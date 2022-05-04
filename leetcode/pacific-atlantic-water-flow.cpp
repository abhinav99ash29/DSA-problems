class Solution {
    vector<int> X,Y;
    int m, n;
public:
    
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        
        for(int k=0;k<4;k++) {
            int i1 = i+X[k];
            int j1 = j+Y[k];
            if (i1<0 || i1>=m || j1<0 || j1>=n) continue;
            if (vis[i1][j1]) continue;
            if (heights[i1][j1]>=heights[i][j]) {
                dfs(i1, j1, heights, vis);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        X = { 1, -1, 0, 0 };
        Y = { 0, 0, 1, -1 };
        vector<vector<bool>> vis1(m, vector<bool>(n, false)), vis2(m, vector<bool>(n, false));
        // left edge
        for(int i=0;i<m;i++) {
            if (!vis1[i][0]) {
                dfs(i,0,heights,vis1);
            }
        }
        
        // top edge
        for(int i=0;i<n;i++) {
            if (!vis1[0][i]) {
                dfs(0,i,heights,vis1);
            }
        }
        
        // right edge
        for(int i=0;i<m;i++) {
            if (!vis2[i][n-1]) {
                dfs(i,n-1,heights,vis2);
            }
        }
        
        // bottom edge
        for(int i=0;i<n;i++) {
            if (!vis2[m-1][i]) {
                dfs(m-1,i,heights,vis2);
            }
        }
        
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};
