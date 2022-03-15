class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0, ans=INT_MIN;
        int i=0;
        while(i<nums.size()) {
            if (curr+nums[i] >= nums[i]) {
                curr+=nums[i];
                ans = max(ans, curr);
                i++;
            } else {
                curr = nums[i];
                ans = max(ans, curr);
                i++;
            }
        }
        return ans;
    }
};
