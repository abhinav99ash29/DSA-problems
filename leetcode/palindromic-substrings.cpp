class Solution {
    int count;
public:
    
    void fn(int i, int j, string& s) {
        while(i>=0 && j<s.size() && s[i] == s[j]) {
            count++;
            j++;
            i--;
        }
    }
    
    int countSubstrings(string s) {
        if (s.size() < 2) return 1;
        count = 0;
        for(int i=0;i<s.size();i++) {
            fn(i,i,s);
            fn(i,i+1,s);
        }
        return count;
    }
};
