class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nq(n, string(n, '.'));
        solveNQueens(res, nq, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string>>& res, vector<string>& nq, int row, int n) {
        if (row==n)
            res.push_back(nq);
        
        for(int i=0;i<n;i++) {
            if(isValid(nq, row, i, n)) {
                nq[row][i] = 'Q';
                solveNQueens(res, nq, row+1, n);
                nq[row][i] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& nq, int row, int col, int n) {
        for(int i=0;i<=row;i++)
            if (nq[i][col] == 'Q')
                return false;
        
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
            if (nq[i][j]=='Q') return false;
        
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
            if (nq[i][j]=='Q') return false;
        
        return true;
    }
};
