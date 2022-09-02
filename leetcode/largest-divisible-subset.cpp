class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(n,{1,-1});
        int mxidx = 0, mxval = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if (nums[i]%nums[j]==0 && dp[i].first<(dp[j].first+1)) {
                    dp[i].first = max(dp[i].first,1+dp[j].first);
                    dp[i].second = j;
                    if (dp[i].first>mxval) {
                        mxval = dp[i].first;
                        mxidx = i;
                    }
                }
            }
        }
        
        vector<int> sol;
        while(mxidx!=-1) {
           sol.push_back(nums[mxidx]);
           mxidx = dp[mxidx].second; 
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
