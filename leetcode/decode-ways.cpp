class Solution {
    vector<int> dp;
public:
    
    int fn(string& s, int i) {
        if (i==s.size()) {
            return 1;
        }
        if (s[i] == '0') return 0;
        
        if (dp[i] != -1) return dp[i];
        
        int ans = fn(s, i+1);
        
        if (i<s.size()-1 && ((s[i]=='1') || (s[i]=='2'&&s[i+1]<='6'))) {
            ans += fn(s,i+2);
        }
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        dp.resize(101,-1);
        return fn(s, 0);
    }
};
