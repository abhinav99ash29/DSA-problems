class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> bd((n*n)+1,-1);
        vector<bool> vis((n*n)+1, false);
        for(int i=1;i<=n*n;i++) {
            int r = n-1-((i-1)/n);
            int c = ((i-1)/n)%2==0 ? (i-1)%n : n-1-((i-1)%n);
            bd[i] = board[r][c];
        }
        queue<int> q;
        q.push(1);
        vis[1] = true;
        int lev = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                int val = q.front(); q.pop();
                if (val == n*n) return lev;
                for(int i=val+1;i<=min(val+6, n*n); i++) {
                    if (vis[i]) continue;
                    if (bd[i]!=-1) {
                        q.push(bd[i]);
                    } else {
                        q.push(i);
                    }
                    vis[i] = true;
                }
            }
            lev++;
        }
        return -1;
    }
};
