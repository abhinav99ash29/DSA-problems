class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& c: cuboids) {
            sort(c.begin(), c.end());
        }
        cuboids.push_back({0,0,0});
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> dp(n, 0);
        int ans = INT_MIN;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if (cuboids[j][0]<=cuboids[i][0] && cuboids[j][1]<=cuboids[i][1] && cuboids[j][2]<=cuboids[i][2]) {
                 dp[i] = max(dp[i], dp[j]+cuboids[i][2]);
                 ans = max(dp[i], ans);   
                }
            }
        }
        return ans;
    }
};
