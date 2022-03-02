class Solution {
public:
    vector<vector<int>> dp;
    int fn(vector<int> nums, int i, int j) {
        if (i>=nums.size() || j<0 || i>j) return 0;
        if (i==j) return dp[i][i] = nums[i];
        if (dp[i][j]!=-1) return dp[i][j];
        
        int choice1 = nums[i]+min(fn(nums,i+1,j-1),fn(nums,i+2,j));
        int choice2 = nums[j]+min(fn(nums,i,j-2),fn(nums,i+1,j-1));
        
        return dp[i][j] = max(choice1, choice2);
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        dp.resize(21,vector<int>(21,-1));
        int v1 = fn(nums,0,nums.size()-1);
        int v2 = min(fn(nums,1,nums.size()-1),fn(nums,0,nums.size()-2));
        
        if (v2>v1) return false;
        
        return true;
    }
};
