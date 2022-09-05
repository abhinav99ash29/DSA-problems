class Solution {
public:
    
    bool check(string s) {
        int n = s.size();
        for(int i=0;i<n/2;i++) {
            if (s[i]!=s[n-1-i]) return false;
        }
        return true;
    }
    
    bool convertcheck(int n, int b) {
        string res = "";
        
        while(n>0) {
            res+=to_string(n%b);
            n/=b;
        }
        reverse(res.begin(), res.end());
        return check(res);
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=(n-2);i++) {
            if (!convertcheck(n,i)) return false;
        }
        return true;
    }
};
