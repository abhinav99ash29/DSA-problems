class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int X[] = {0,0,-1,1};
        int Y[] ={1,-1,0,0};
        int m = heights.size();
        int n = heights[0].size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<vector<int>> grid(m, vector<int>(n, INT_MAX));
        q.push({0,0});
        
        while(!q.empty()) {
            pair<int, int> temp = q.top(); q.pop();
            int x = temp.second/100, y = temp.second%100;
            int effort = temp.first;
            if (effort >= grid[x][y]) continue;
            if (x == m-1 && y == n-1) {
                return effort;
            }
            grid[x][y] = effort;
            for(int i=0;i<4;i++) {
                int xx = x + X[i];
                int yy = y + Y[i];
                if (xx>=0 && xx < m && yy >= 0 && yy < n) {
                    int neweffort = max(grid[x][y], abs(heights[xx][yy]-heights[x][y]));
                    if (neweffort < grid[xx][yy]) {
                        q.push({neweffort, xx*100 + yy});
                    }
                }
            }
        }
        return -1;
    }
};
