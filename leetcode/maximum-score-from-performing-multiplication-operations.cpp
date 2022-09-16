class Solution {
public:
    
    int fn(vector<int>& nums, int i, vector<int>& mult, int left, int right, vector<vector<int>>& dp) {
        // cout<<i<<" "<<left<<" "<<right<<endl;
        if (i>=mult.size() || left>right) return 0;
        if (dp[left][i]!=INT_MAX) return dp[left][i];
        int sol = (nums[left]*mult[i])+fn(nums,i+1,mult,left+1,right,dp);
        sol = max(sol, (nums[right]*mult[i])+fn(nums,i+1,mult,left, right-1,dp));
        
        return dp[left][i] = sol;
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(multipliers.size(),vector<int>(multipliers.size(),INT_MAX));
        return fn(nums,0,multipliers,0,nums.size()-1,dp);
    }
};
