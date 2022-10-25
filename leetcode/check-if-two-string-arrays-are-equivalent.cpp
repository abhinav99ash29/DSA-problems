class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        for(string& s: word1)
            for(char& c: s)
                s1.push_back(c);
        for(string& s: word2)
            for(char& c: s)
                s2.push_back(c);
        int n1 = s1.size(), n2 = s2.size();
        if (n1!=n2) return false;
        for(int i=0;i<n1;i++) {
            if (s1[i]!=s2[i]) return false;
        }
        return true;
    }
};
