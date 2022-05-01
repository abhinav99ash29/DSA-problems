class Solution {
    string actual(string &s) {
        string s1 = "";
        for(int i=0;i<s.size();i++) {
            if (s1.size() == 0 && s[i]=='#') continue;
            else if (s[i] == '#') {
                s1.pop_back();
            }
            else
                s1+=s[i];
        }
        return s1;
    }
public:
    bool backspaceCompare(string s, string t) {
        return actual(s)==actual(t);
    }
};
