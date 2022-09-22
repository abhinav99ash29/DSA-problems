class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i=0,j=0;
        while(j<n) {
            while(s[j]!=' ' && j<n-1) {
                j++;
            }
            if (s[j]==' ') {
                reverse(s.begin()+i,s.begin()+j);
            }
            if (j==n-1) {
                reverse(s.begin()+i,s.begin()+j+1);
            }
            i=j+1;
            j++;
        }
        return s;
    }
};
