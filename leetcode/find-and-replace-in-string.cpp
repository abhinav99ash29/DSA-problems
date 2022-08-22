class Solution {
public:
    string findReplaceString(string s, vector<int>& idx, vector<string>& src, vector<string>& tgt) {
        map<int, int> mp;
        int n = src.size();
        for(int i=0;i<n;i++) {
            if (s.substr(idx[i],src[i].size()) == src[i]) {
                mp[idx[i]] = i;
            }
        }
        string str = "";
        int i = 0;
        while(i<s.size()) {
            if (mp.count(i)) {
                str += tgt[mp[i]];
                i+=src[mp[i]].size();
            } else {
                str += s[i];
                i++;
            }
        }
        return str;
    }
};
