class Solution {
public:
    bool canChange(string start, string target) {
        string st = "", tt = "";
        for(int i=0;i<start.size();i++) {
            if (start[i]!='_') st+=start[i];
            if (target[i]!='_') tt+=target[i];
        }
        if (st!=tt) return false;
        vector<int> ls,lt,rs,rt;
        for(int i=0;i<start.size();i++) {
            if (start[i]=='L') ls.push_back(i);
            if (start[i]=='R') rs.push_back(i);
        }
        for(int i=0;i<target.size();i++) {
            if (target[i]=='L') lt.push_back(i);
            if (target[i]=='R') rt.push_back(i);
        }
        if (ls.size()!=lt.size() || rs.size()!=rt.size()) return false;
        for(int i=0;i<ls.size();i++) {
            if (ls[i]<lt[i]) return false;
        }
        for(int i=0;i<rs.size();i++) {
            if (rs[i]>rt[i]) return false;
        }
        return true;
    }
};
