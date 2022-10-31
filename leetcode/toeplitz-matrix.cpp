class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        for(int i=0;i<m;i++) {
            int x = matrix[i][0];
            int j=0,p=i;
            while(p<m && j<n) {
                if (x!=matrix[p][j]) return false;
                p++;
                j++;
            }
        }
        for(int j=1;j<n;j++) {
            int x = matrix[0][j];
            int i=0,p=j;
            while(i<m && p<n) {
                if (x!=matrix[i][p]) return false;
                p++;
                i++;
            }
        }
        return true;
    }
};
