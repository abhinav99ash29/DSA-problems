class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> lt(n,INT_MAX), rt(n,INT_MAX);
        for(int i=n-1;i>=0;i--) {
            if (s[i]=='L') lt[i]=0;
            else if (s[i]=='.') {
                if (i<n-1 && lt[i+1]!=INT_MAX) lt[i] = lt[i+1]+1;
            }
        }
        for(int i=0;i<n;i++) {
            if (s[i]=='R') rt[i]=0;
            else if (s[i]=='.') {
                if (i>0 && rt[i-1]!=INT_MAX) rt[i] = rt[i-1]+1;
            } 
        }
        string sol = "";
        for(int i=0;i<n;i++) {
            if (lt[i]==rt[i]) sol+='.';
            else if (lt[i]<rt[i]) sol+='L';
            else sol+='R';
        }
        return sol;
    }
};
