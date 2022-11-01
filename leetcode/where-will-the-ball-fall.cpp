class Solution {
    vector<int> X,Y;
public:
    int dfs(int x, int y, vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        if (x==m) return y;
        if (arr[x][y]==1) {
            return (y==n-1||arr[x][y+1]==-1) ? -1 : dfs(x+1,y+1,arr);
        }
        
        return (y==0 || arr[x][y-1]==1) ? -1 : dfs(x+1,y-1,arr);
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
