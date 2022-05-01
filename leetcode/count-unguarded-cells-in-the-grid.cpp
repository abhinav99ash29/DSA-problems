class Solution {
public:
    void explore(int i, int j, vector<vector<int>> &vis, vector<int> dir, int m, int n) {
        while(i<m && j<n && i>=0 && j>=0 && vis[i][j]!=2 && vis[i][j]!=-2) {
            vis[i][j] = 1;
            i+=dir[0];
            j+=dir[1];
        }
    }
    
    int count (int m, int n, vector<vector<int>> &vis) {
        int cnt = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (vis[i][j]==-1)
                    cnt++;
            }
        }
        return cnt;
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, -1));
        int X[] = {1, -1, 0, 0};
        int Y[] = {0, 0, 1, -1};
        
        for(int i=0;i<walls.size();i++) {
            int x = walls[i][0];
            int y = walls[i][1];
            vis[x][y] = 2;
        }
        
        for(int i=0;i<guards.size();i++) {
            int x = guards[i][0];
            int y = guards[i][1];
            vis[x][y] = -2;
        }
        
        for(int i=0;i<guards.size();i++) {
            int x = guards[i][0];
            int y = guards[i][1];
            vis[x][y] = 1;
            for(int j=0;j<4;j++) {
                explore(x, y, vis, {X[j], Y[j]}, m, n);
            }
            vis[x][y] = -2;
        }        
        return count(m, n, vis);
    }
};
