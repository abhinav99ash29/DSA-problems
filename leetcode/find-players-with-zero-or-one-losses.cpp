class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp1,mp2;
        for(int i=0;i<matches.size();i++) {
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto m: mp1) {
             if (mp2[m.first]==0) ans[0].push_back(m.first);
        }
        for(auto m: mp2) {
            if (m.second == 1) ans[1].push_back(m.first);
        }
        return ans;
    }
};
