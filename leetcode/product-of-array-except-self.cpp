class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), x;
        vector<int> ans(n,1);
        x = 1;
        for(int i=1;i<n;i++) {
            x*=nums[i-1];
            ans[i] = x;
        }
        x=1;
        for(int i=n-2;i>=0;i--) {
            x*=nums[i+1];
            ans[i]*=x;
        }
        return ans;
    }
};
