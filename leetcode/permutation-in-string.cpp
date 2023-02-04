class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            if (a[i]!=b[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26, 0), b(26, 0);
        for(char& c: s1) {
            a[c-'a']++;
        }
        int m = s1.size(), n = s2.size();
        int i=0, j=0;
        while(j<n) {
            b[s2[j]-'a']++;
            if (j-i+1 == m) {
                if(check(a,b)) return true;
                b[s2[i]-'a']--;
                i++;
            }
            j++;
        }
        return false;
    }
};
