class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ansi=0,ansj=0;
        int it=0,jt=0;
        for(int i=0;i<n;i++) {
            it=i;jt=i;
            while(it-1>=0 && jt+1<n && s[it-1]==s[jt+1]) {
                it--;jt++;
            }
            if (jt-it > ansj-ansi) {
                cout<<it<<" "<<jt<<endl;
                ansj=jt;ansi=it;
            }
        }
        for(int i=0;i+1<n;i++) {
            if(s[i]==s[i+1])
            {
                int it=i,jt=i+1;
                while(it-1>=0 && jt+1<n && s[it-1]==s[jt+1]) {
                    it--,jt++;
                }
                if(jt-it>ansj-ansi) {
                    cout<<it<<" "<<jt<<endl;
                    ansj=jt,ansi=it;
                }
            }
        }
        string ans="";
        for(int i=ansi;i<=ansj;i++) {
            ans+=s[i];
        }
        return ans;
    }
};

// https://leetcode.com/problems/longest-palindromic-substring/
