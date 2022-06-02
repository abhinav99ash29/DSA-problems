class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
       
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (!i || !j || mat[i][j]=='0') {
                    dp[i][j] = mat[i][j] - '0';
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                ans = max(dp[i][j], ans);
            }
        }
        
        return ans*ans;
    }
};
