class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26, 0);
        for(int i=0;i<26;i++) {
            v[order[i]-'a'] = i;
        }
        for(int i=1;i<words.size();i++) {
            string w1 = words[i-1];
            string w2 = words[i];
            int j = 0;
            for(;j<min(w1.size(), w2.size());j++) {
                if (v[w1[j]-'a'] < v[w2[j]-'a']) break;
                if (v[w1[j]-'a'] > v[w2[j]-'a']) return false;
            }
            if (j==min(w1.size(), w2.size()) && w1.size()>w2.size()) return false;
        }
        return true;
    }
};
