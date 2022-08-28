class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int j=0;j<n;j++) {
            int x = 0, y = j;
            vector<int> v;
            while(x<m && y<n) {
                v.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(v.begin(), v.end());
            x = 0; y = j; int k=0;
            while(x<m && y<n) {
                mat[x][y] = v[k];
                x++;
                y++;
                k++;
            }
        }
        
        for(int i=1;i<m;i++) {
            int x = i, y = 0;
            vector<int> v;
            while(x<m && y<n) {
                v.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(v.begin(), v.end());
            x = i; y = 0; int k=0;
            while(x<m && y<n) {
                mat[x][y] = v[k];
                x++;
                y++;
                k++;
            }
        }
        
        return mat;
    }
};
