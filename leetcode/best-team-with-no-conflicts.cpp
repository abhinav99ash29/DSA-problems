class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++) {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        vector<int> dp;
        for(pair<int,int> p: v) dp.push_back(p.second);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if (v[j].second<=v[i].second) {
                    dp[i] = max(dp[i], dp[j]+v[i].second);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
