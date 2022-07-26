class Solution {
public:
    
    bool fn(vector<vector<char>>& board, int i, int j,
            vector<vector<bool>>& row, vector<vector<bool>>& col,
           vector<vector<bool>>& grid) {
        if (i==9) return true;
        if (board[i][j]!='.') {
            if (j<8) return fn(board,i,j+1,row,col,grid);
            else return fn(board,i+1,0,row,col,grid);
        }
        int grd = ceil((float)(j+1)/3) + (ceil((float)(i+1)/3)-1)*3 - 1;
        for(int k=1;k<=9;k++) {
            if (!row[i][k-1] && !col[j][k-1]
                && !grid[grd][k-1]) {
                row[i][k-1] = true;
                col[j][k-1] = true;
                grid[grd][k-1] = true;
                board[i][j] = (char)k+'0';
                bool ret = false;
                if (j<8) ret = fn(board,i,j+1,row,col,grid);
                else ret = fn(board,i+1,0,row,col,grid);
                if (ret) return true;
                row[i][k-1] = false;
                col[j][k-1] = false;
                grid[grd][k-1] = false;
                board[i][j] = '.';
            }
        }
        return false;
        
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9,false)), col(9,vector<bool>(9,false)), grid(9,vector<bool>(9, false));
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if (board[i][j]>='1' && board[i][j]<='9') {
                    row[i][board[i][j]-'1'] = true;
                    col[j][board[i][j]-'1'] = true;
                    int grd = ceil((float)(j+1)/3) + (ceil((float)(i+1)/3)-1)*3 - 1;
                    grid[grd][board[i][j]-'1'] = true;
                }
            }
        }
        
        fn(board,0,0,row,col,grid);
    }
};
