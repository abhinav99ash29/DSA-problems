class Solution {
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
public:
    
    bool dfs(int i, int j, vector<vector<bool>>& vis, int k, string& word, vector<vector<char>>& board) {
        if (k==word.size()) return true;
        if (i<0||i>=board.size()||j<0||j>=board[0].size()||vis[i][j]||board[i][j]!=word[k]) return false;
        vis[i][j] = true;
        for(int p=0;p<4;p++) {
            int i1 = i+X[p], j1 = j+Y[p];
            if (dfs(i1,j1,vis,k+1,word,board)) return true;
        }
        vis[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>> points;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if (board[i][j]==word[0])
                    points.push_back({i,j});
            }
        }
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        for(vector<int>& v: points) {
            if (dfs(v[0],v[1],vis,0,word,board)) return true;
        }
        return false;
    }
};
