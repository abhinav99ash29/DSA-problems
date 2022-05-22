class Solution {
public:
    
    int fn(int i, vector<int>& nums, vector<int>& dp) {
        if (i>=nums.size()) return INT_MAX;
        if (i==nums.size()-1) return 0;
        if (dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for(int j=nums[i];j>=1;j--) {
            int x = fn(i+j,nums,dp);
            if (x!=INT_MAX)
            ans = min(ans, 1+x);
        }
        return dp[i] = ans;
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return fn(0,nums,dp);
    }
};
