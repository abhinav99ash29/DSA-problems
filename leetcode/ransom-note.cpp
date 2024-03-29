class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26,0);
        for(char& c: magazine) v[c-'a']++;
        for(char& c: ransomNote) {
            if (v[c-'a'] > 0) v[c-'a']--;
            else return false;
        }
        return true;
    }
};
