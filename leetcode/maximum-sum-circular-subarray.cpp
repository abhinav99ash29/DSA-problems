class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currmax = 0, currmin = 0, mx = INT_MIN, mn = INT_MAX;
        int total = 0;
        for(int i=0;i<n;i++) {
            total+=nums[i];
            currmax = max(currmax+nums[i], nums[i]);
            mx = max(mx, currmax);
            currmin = min(currmin+nums[i], nums[i]);
            mn = min(mn, currmin);
        }
        return mx > 0 ? max(mx, total-mn) : mx;
    }
};
