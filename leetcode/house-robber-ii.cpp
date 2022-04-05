class Solution {
    vector<int> dp;
public:
    
    int fn(vector<int>& nums, int i, int end) {
        if (i >= end) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i]+fn(nums,i+2,end), fn(nums,i+1,end));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        dp.resize(n,-1);
        int ans1 = fn(nums,0,n-1);
        fill(dp.begin(), dp.end(),-1);
        return max(ans1, fn(nums,1,n));
    }
};
