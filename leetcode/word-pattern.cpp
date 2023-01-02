class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        unordered_map<string, char> m1;
        string w = "";
        int k = 0;
        for(int i=0;i<s.size();i++) {
            if (s[i]==' ') {
                if (k==pattern.size()) return false;
                if (m.count(pattern[k])) {
                    if (m[pattern[k]] != w) return false;
                } else if (m1.count(w)) {
                    if (m1[w] != pattern[k]) return false;
                } else {
                    m[pattern[k]] = w;
                    m1[w] = pattern[k];
                }
                w = "";
                k++;
            } else {
                w+=s[i];
            }
        }
        if (m.count(pattern[k])) {
            if (m[pattern[k]] != w) return false;
        } else if (m1.count(w)) {
            if (m1[w] != pattern[k]) return false;
        }
        if (k!=pattern.size()-1) return false;
        return true;
    }
};
