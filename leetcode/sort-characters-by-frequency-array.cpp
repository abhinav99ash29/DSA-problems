class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char& c: s) {
            mp[c]++;
        }
        vector<pair<int, char>> v;
        for(auto& i: mp) {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string ans = "";
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[i].first;j++) {
                ans+=v[i].second;
            }
        }
        return ans;
    }
};

