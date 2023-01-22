class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n+1, 0));
        for(vector<int>& v: queries) {
            int r1 = v[0], c1 = v[1], r2 = v[2], c2 = v[3];
            for(int i=r1;i<=r2;i++) {
                mat[i][c1]+=1;
                mat[i][c2+1]-=1;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=1;j<n;j++) {
                mat[i][j]=mat[i][j]+mat[i][j-1];
            }
        }
        for(int i=0;i<n;i++) mat[i].pop_back();
        return mat;
    }
};
