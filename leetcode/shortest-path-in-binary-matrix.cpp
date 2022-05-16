class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int X[] = {0,0,1,-1,1,-1,1,-1};
        int Y[] = {1,-1,0,0,1,-1,-1,1};
        int m = grid.size();
        int n = grid[0].size();
        
        if (grid[0][0]==1||grid[m-1][n-1]==1) return -1;
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<vector<int>> q;
        
        q.push({0,0,1});
        vis[0][0]=true;
        
        while(!q.empty()) {
            vector<int> point = q.front();
            q.pop();
            int x = point[0], y = point[1], l = point[2];
            if (x==m-1&&y==n-1) return l;
            for(int i=0;i<8;i++) {
                int x1 = x+X[i];
                int y1 = y+Y[i];
                if (x1>=0&&x1<m&&y1>=0&&y1<n&&!vis[x1][y1]&&grid[x1][y1]==0) {
                    vis[x1][y1] = true;
                    q.push({x1,y1,l+1});
                }
            }
        }
        return -1;
    }
};
