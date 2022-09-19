class Solution {
public:
    
    void findAssign(string s, unordered_map<string, vector<string>>& m) {
        string dir = "";
        int i=0, n = s.size();
        while(s[i]!=' ') {
            dir+=s[i];
            i++;
        }
        i++;
        while(i<n) {
            if (s[i]==' ') i++;
            string file = "";
            while(i<n && s[i]!='(') {
                file+=s[i];
                i++;
            }
            i++;
            string content = "";
            while(i<n && s[i]!=')') {
                content+=s[i];
                i++;
            }
            i++;
            m[content].push_back(dir+'/'+file);
        }
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for(string s: paths) {
            findAssign(s,m);
        }
        vector<vector<string>> sol;
        for(auto& it: m) {
            if (it.second.size()>1) {
                sol.push_back(it.second);
            }
        }
        return sol;
    }
};
