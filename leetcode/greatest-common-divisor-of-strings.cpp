class Solution {
public:

    string find(string s1, string s2) {
        if (s2=="") return s1;
        if (s1.size()<s2.size()) return find(s2, s1);
        int i=0;
        int m = s1.size(), n = s2.size();
        while(i<m) {
            if (s1[i] != s2[i%n]) return "";
            i++;
        }
        return find(s2, s1.substr(m-(m%n)));
    }

    string gcdOfStrings(string str1, string str2) {
        return find(str1, str2);
    }
};
