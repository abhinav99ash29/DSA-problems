class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> brd(n, vector<int>(n, 0));
        int cnt = 0;
        totalNQueens(brd, 0, n, cnt);
        return cnt;
    }
private:
    void totalNQueens(vector<vector<int>>& brd, int row, int n, int& cnt) {
        if (row == n) cnt++;
        for(int i=0;i<n;i++) {
            if (isValid(brd, row, i, n)) {
                brd[row][i] = 1;
                totalNQueens(brd, row+1, n, cnt);
                brd[row][i] = 0;
            }
        }
    }
    
    bool isValid(vector<vector<int>>& brd, int row, int col, int n) {
        for(int i=0;i<n;i++) {
            if (brd[i][col])
                return false;
        }
        
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
            if (brd[i][j]) return false;
        
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
            if (brd[i][j]) return false;
        
        return true;
    }
};
