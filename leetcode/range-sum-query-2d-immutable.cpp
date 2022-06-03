class NumMatrix {
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix1) {
        int m = matrix1.size();
        int n = matrix1[0].size();
        matrix.resize(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                matrix[i][j] = matrix1[i][j];
        
        for(int i=0;i<m;i++) {
            for(int j=1;j<n;j++) {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        
        for(int j=0;j<n;j++) {
            for(int i=1;i<m;i++) {
                matrix[i][j]+=matrix[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        if (!row1 && !col1) return matrix[row2][col2];
        
        if (!row1) return matrix[row2][col2] - matrix[row2][col1-1];
        
        if (!col1) return matrix[row2][col2] - matrix[row1-1][col2];
        
        return matrix[row2][col2] - matrix[row1-1][col2] - matrix[row2][col1-1] + matrix[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
