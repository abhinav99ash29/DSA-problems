class Solution {
    vector<int> dp;
public:
    
    int fn(vector<int>& nums, int target) {
        if (target == 0) return 1;
        if (dp[target]!=-1) return dp[target];
        
        int cnt=0;
        for(int i=0;i<nums.size();i++) {
            if (target >= nums[i])
            cnt+=combinationSum4(nums, target-nums[i]);
        }
        return dp[target] = cnt;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
       dp.resize(1001,-1);
       return fn(nums, target); 
    }
    
};
