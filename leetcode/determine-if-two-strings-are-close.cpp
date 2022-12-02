class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> mp1, mp2;
        for(char& c: word1) mp1[c]++;
        for(char& c: word2) mp2[c]++;
        for(char&c: word1) {
            if (!mp2.count(c)) return false;
        }
        for(char&c: word2) {
            if (!mp1.count(c)) return false;
        }
        for(char&c: word1) mp1[c]++;
        for(char&c: word2) mp2[c]++;
        vector<int> v1, v2;
        for(auto& itr: mp1) v1.push_back(itr.second);
        for(auto& itr: mp2) v2.push_back(itr.second);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i=0;i<v1.size();i++) {
            if (v1[i]!=v2[i]) return false;
        }
        return true;
    }
};
