class Solution {
    vector<int> dp;
public:
    
    int fn(vector<int>& nums, int i) {
        if (i>=nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i]+fn(nums,i+2), fn(nums,i+1));
        
    }
    
    int rob(vector<int>& nums) {
        dp.resize(101,-1);
        return fn(nums, 0);
    }
};
