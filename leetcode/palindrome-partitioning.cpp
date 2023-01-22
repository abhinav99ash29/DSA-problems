class Solution {
public:
    vector<vector<bool>> dp;

    void fn(int i, string& s, vector<vector<string>>& ans, vector<string>& sofar) {
        int n = s.size();
        if (i==n) ans.push_back(sofar);
        for(int j=i;j<n;j++) {
            string str = s.substr(i,j-i+1);
            if (dp[i][j]) {
                sofar.push_back(str);
                fn(j+1,s,ans,sofar);
                sofar.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string& s) {
        int n = s.size();
        dp.resize(n, vector<bool>(n, false));
        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                if (s[i]==s[j] && (i-j <= 2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> sofar;
        fn(0,s,ans,sofar);
        return ans;
    }
};
