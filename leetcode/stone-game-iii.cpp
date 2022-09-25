class Solution {
public:
    int fn(int i, int n, vector<int>& nums, vector<int>& dp) {
        if (i>=n) return 0;
        if (dp[i]!=INT_MIN) return dp[i];
        int x=INT_MIN, y=INT_MIN, z=INT_MIN;
        x = nums[i]-fn(i+1,n,nums,dp);
        if (i<n-1) {
            y = (nums[i]+nums[i+1])-fn(i+2,n,nums,dp);
        }
        if (i<n-2) {
            z = (nums[i]+nums[i+1]+nums[i+2])-fn(i+3,n,nums,dp);
        }
        int sol = max({x,y,z});
        return dp[i] = sol;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,INT_MIN);
        int sol = fn(0,n,stoneValue,dp);
        // cout<<sol<<endl;
        if (sol>0) return "Alice";
        else if (sol<0) return "Bob";
        return "Tie";
    }
};
