class Solution {
    int countm(string s) {
        int cnt = 0;
        for(char c: s) {
            if (c=='0')
                cnt++;
        }
        return cnt;
    }
public:
    // bottom up approach
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(string str: strs) {
            int ms = countm(str);
            int ns = str.size() - ms;
            for(int i=m;i>=ms;i--) {
                for(int j=n;j>=ns;j--) {
                    dp[i][j] = max(dp[i][j], 1+dp[i-ms][j-ns]);
                }
            }
        }
        return dp[m][n];
    }
};
