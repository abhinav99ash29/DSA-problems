class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return n; // using LIS on differences
        if (n==2) return nums[0]!=nums[1] ? 2 : 1;
        vector<int> diff;
        for(int i=0;i<n-1;i++) {
            if (nums[i+1]-nums[i] != 0)
            diff.push_back(nums[i+1]-nums[i]);
        }
        vector<int> dp(diff.size(), 1);
        
        for(int i=1;i<diff.size();i++) {
            for(int j=0;j<i;j++) {
                if ((diff[i]>0 && diff[j]<0)||(diff[i]<0&&diff[j]>0)) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        if (diff.size() == 0) return 1;
        return *max_element(dp.begin(), dp.end())+1;
    }
};
