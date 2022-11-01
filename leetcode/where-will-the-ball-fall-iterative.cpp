class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> sol(n,-1);
        for(int j=0;j<n;j++) {
            int curr = j;
            for(int i=0;i<m;i++) {
                int nj = curr+grid[i][curr];
                if (nj<0 || nj>n-1 || grid[i][curr]!=grid[i][nj]) {
                    sol[j] = -1;
                    break;
                }
                sol[j] = nj;
                curr = nj;
            }
        }
        return sol;
    }
};
