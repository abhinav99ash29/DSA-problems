class Solution {
public:
    
    int len(int n) {
        if (n==1) return 0;
        else if (n<10) return 1;
        else if (n<100) return 2;
        return 3;
    }
    
    int fn(string& s, int idx, int k, vector<vector<int>>& dp) {
        if (k<0) return s.size();
        if (idx==s.size() || s.size()-idx<=k) return 0;
        if (dp[idx][k]!=-1) return dp[idx][k];
        vector<int> cnt(26,0);
        int most = 0;
        int ans = s.size();
        for(int i=idx;i<s.size();i++) {
            cnt[s[i]-'a']++;
            most = max(most, cnt[s[i]-'a']);
            ans = min(ans, 1+len(most)+fn(s,i+1,k-(i-idx+1-most), dp));
        }
        return dp[idx][k] = ans;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(k+1,-1));
        return fn(s,0,k,dp);
    }
};
