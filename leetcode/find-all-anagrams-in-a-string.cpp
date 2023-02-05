class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {
        for(int i=0;i<26;i++) {
            if (a[i]!=b[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> a(26,0), b(26, 0);
        for(char& c: p) b[c-'a']++;
        vector<int> ans;
        int i=0,j=0;
        while(j<m) {
            a[s[j]-'a']++;
            if (j-i+1 == n) {
                if (check(a, b)) ans.push_back(i);
                a[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
