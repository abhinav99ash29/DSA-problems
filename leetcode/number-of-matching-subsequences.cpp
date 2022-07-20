class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> smap(26);
        for(int i=0;i<s.size();i++) {
            smap[s[i]-'a'].push_back(i);
        }
        int sol = 0;
        for(string& word: words) {
           int x = -1;
           bool found = true;
           for(char& c: word) {
               auto it = upper_bound(smap[c-'a'].begin(), smap[c-'a'].end(), x);
               if (it!=smap[c-'a'].end()) {
                   x=*it;
               } else {
                   found = false;
                   break;
               }
           }
           if (found) sol++;
        }
        return sol;
    }
};
