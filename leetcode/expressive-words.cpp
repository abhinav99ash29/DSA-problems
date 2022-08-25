class Solution {
public:
    vector<pair<int,int>> findcnt(string s) {
        vector<pair<int, int>> scnt;
        for(int i=0;i<s.size();i++) {
            char c = s[i];
            int cnt = 1;
            while(i<s.size() && s[i]==s[i+1]) {
                cnt++;
                i++;
            }
            scnt.push_back({c,cnt});
        }
        return scnt;
    }
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<int, int>> scnt = findcnt(s);
        int sol = 0;
        for(string& w: words) {
            vector<pair<int, int>> wcnt = findcnt(w);
            if (wcnt.size()!=scnt.size()) continue;
            int n = wcnt.size();
            int i=0;
            bool flag = true;
            bool applied = false;
            while(i<n) {
                // cout<<(char)scnt[i].first<<" "<<scnt[i].second<<","<<(char)wcnt[i].first<<" "<<wcnt[i].second<<endl;
                if (scnt[i].first != wcnt[i].first || wcnt[i].second > scnt[i].second
                   || (scnt[i].second > wcnt[i].second && scnt[i].second <= 2)) {
                    flag = false;
                    break;
                } else if (scnt[i].second > wcnt[i].second && scnt[i].second >= 3) {
                    applied = true;
                }
                i++;
            }
            if (!flag) continue;
            if (applied) {
              sol++;  
            }
        }
        return sol;
    }
};
