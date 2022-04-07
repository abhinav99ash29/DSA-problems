class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        vector<int> vec(26,0);
        for(int i=0;i<s.size();i++) {
            vec[s[i]-'a']++;
            vec[t[i]-'a']--;   
        }
        return *max_element(vec.begin(), vec.end()) == 0 && *min_element(vec.begin(), vec.end()) == 0;
    }
};
