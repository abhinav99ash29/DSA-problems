class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        int n = groupSizes.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            int x = groupSizes[i];
            mp[x].push_back(i);
            if (mp[x].size() == x) {
                ans.push_back(mp[x]);
                mp[x].clear();
            }
        }
        
        return ans;
    }
};
