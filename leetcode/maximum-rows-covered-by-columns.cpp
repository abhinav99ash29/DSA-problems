class Solution {
    int mx;
public:
    
    int check(vector<vector<int>>& mat, vector<bool>& v) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt=0;
        for(int i=0;i<n;i++) {
            bool flag = true;
            for(int j=0;j<m;j++) {
                if (mat[i][j]==1&&v[j]==false) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }
        // for(int i: v) cout<<i<<" ";
        // cout<<endl<<cnt<<endl;
        return cnt;
    }
    
    void rec(int i, vector<vector<int>>& mat, int cols, vector<bool>& sofar, vector<bool>& vis) {
        if (cols==0) {
            mx = max(mx, check(mat, sofar));
        }
        if (i>=mat[0].size()) return;
        vis[i] = true;
        sofar[i] = true;
        rec(i+1,mat,cols-1,sofar,vis);
        vis[i] = false;
        sofar[i] = false;
        rec(i+1,mat,cols,sofar,vis);
    }
    
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size();
        int n = mat[0].size();
        vector<bool> vis(n,false);
        vector<bool> sofar(n,false);
        rec(0,mat,cols,sofar,vis);
        return mx;
    }
};
