class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int idx = 0;
        
        for(int i=1;i<nums.size();i++) {
            if (ans[idx]<nums[i]) {
                ans.push_back(nums[i]);
                idx++;
            } else {
                int lb = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[lb] = nums[i];
            }
        }
        return ans.size();
    }
};
