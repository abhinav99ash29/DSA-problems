class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size()!=word2.size()) return false;
        vector<int> c1(26,0), c2(26,0);
        for(char& c: word1) c1[c-'a']++;
        for(char& c: word2) c2[c-'a']++;
        for(int i=0;i<26;i++) {
            if (c1[i]!=0 && c2[i]!=0) continue;
            if (c1[i]!=0 || c2[i]!=0) return false;
        }
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        for(int i=0;i<26;i++) {
            if (c1[i]!=c2[i]) return false;
        }
        return true;
    }
};
