class Solution {
    long int mod = (int)1e9+7;
public:
    
    int rec(string& s, int i, vector<int>& dp) {
        int n = s.size();
        if (i>n) return 0;
        if (i==n) return 1;
        if (s[i]=='0') return 0;
        if (dp[i] != -1) return dp[i];
        
        long int cnt = rec(s,i+1,dp)%mod;
        
        if (s[i]=='*') {
            cnt=(cnt*9)%mod;
        }
        
        if (i+1<n && (s[i]=='1' && s[i+1] != '*') || (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6')) {
            cnt= (cnt+rec(s,i+2,dp)%mod)%mod;
        }
        
        if (i+1<n && (s[i]=='1' && s[i+1] == '*')) {
            cnt=(cnt+((long int)9*rec(s,i+2,dp)%mod)%mod)%mod;
        }
        
        if (i+1<n && (s[i]=='2' && s[i+1] == '*')) {
            cnt=(cnt+((long int)6*rec(s,i+2,dp)%mod)%mod)%mod;
        }
        
        if (i+1<n && s[i]=='*' && s[i+1]=='*') {
            cnt=(cnt+((long int)15*rec(s,i+2,dp)%mod)%mod)%mod;
        }
        
        if (i+1<n && s[i]=='*' && s[i+1]!='*') {
            if (s[i+1]<='6') {
                cnt=(cnt+((long int)2*rec(s,i+2,dp)%mod)%mod)%mod;
            } else {
                cnt=(cnt+1*rec(s,i+2,dp)%mod)%mod;   
            }
        }
        
        return dp[i] = cnt%mod;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return rec(s,0,dp);
    }
};
