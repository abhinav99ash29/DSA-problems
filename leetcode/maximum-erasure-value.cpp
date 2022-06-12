class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++) {
            sum[i]+=sum[i-1] + nums[i-1];
        }
        int i=0, j=0;
        map<int, int> vis;
        int currsum = 0, maxsum = 0;
        while(j<n) {
            if (vis.count(nums[j])>0 && i<(vis[nums[j]]+1)) {
                currsum = currsum - sum[vis[nums[j]]+1] + sum[i];
                i = vis[nums[j]]+1;
            }
            vis[nums[j]] = j;
            currsum+=nums[j];
            maxsum = max(maxsum, currsum);
            j++;
        }
        return maxsum;
    }
};
