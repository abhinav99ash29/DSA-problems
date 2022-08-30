class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int k=0;k<n/2;k++) {
            int i=k,j=k;
            int x = n-1-(2*k);
            while(j<n-k-1) {    
                int r = j-i, c = x-(j-i);
                int i1=i+r,j1=j+c;
                int i2=i1+c,j2=j1-r;
                int i3=i2-r,j3=j2-c;
                int temp = matrix[i3][j3];
                matrix[i3][j3] = matrix[i2][j2];
                matrix[i2][j2] = matrix[i1][j1];
                matrix[i1][j1] = matrix[i][j];
                matrix[i][j] = temp;
                j++;
            }
        }
    }

};
