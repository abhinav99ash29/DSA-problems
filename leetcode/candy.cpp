class Solution { // Sorting based solution
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> nums1;
        for(int i=0;i<n;i++) {
            nums1.push_back({nums[i],i});
        }
        sort(nums1.begin(), nums1.end());
        vector<int> ans(n, -1);
        for(int i=0;i<n;i++) {
            int idx = nums1[i][1];
            int val = nums1[i][0];
            int l = -1, r = -1;
            int lval = nums[idx], rval = nums[idx];
            if (idx-1>=0) {
                l = ans[idx-1];
                lval = nums[idx-1];
            }
            if (idx+1 < n) {
                r = ans[idx+1];
                rval = nums[idx+1];
            }
            if (lval>=val && rval>=val) ans[idx]=1;
            else if (lval<val && rval<val) ans[idx] = max(l,r)+1;
            else if (lval<val) ans[idx] = l+1;
            else if (rval<val) ans[idx] = r+1;
            
        }
        int sum = 0;
        for(int& i: ans) sum+=i;
        return sum;
    }
};
