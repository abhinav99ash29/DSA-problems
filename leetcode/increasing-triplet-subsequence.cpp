class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> lmn(n,INT_MAX), rmx(n, INT_MIN);
        int mn = INT_MAX;
        for(int i=0;i<n;i++) {
            mn = min(nums[i], mn);
            lmn[i] = mn;
        }
        int mx = INT_MIN;
        for(int i=n-1;i>=0;i--) {
            mx = max(nums[i],mx);
            rmx[i] = mx;
        }
        for(int i=0;i<n;i++) {
            if (lmn[i]<nums[i] && nums[i]<rmx[i]) return true;
        }
        return false;
    }
};
