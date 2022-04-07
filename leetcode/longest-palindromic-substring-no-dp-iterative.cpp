class Solution {
    int l, r;
public:
    void fn(int i, int j, string& s) {
        while (i>=0 && j<s.size() && s[i] == s[j]) {
            j++;
            i--;
        }
        if (j-i-1 > (r-l+1)) {
            r = j-1;
            l = i+1;
        }
    }
    
    
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        for(int i=0;i<s.size();i++) {
            // cout<<i<<endl;
            fn(i,i,s);
            fn(i,i+1,s);
        }
        return s.substr(l,(r-l+1));
    }
};
