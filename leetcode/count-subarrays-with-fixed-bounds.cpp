class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long cnt = 0;
        int jbad = -1, jmin = -1, jmax = -1;
        for(int i=0;i<n;i++) {
            if (nums[i]<minK || nums[i]>maxK) jbad = i;
            if (nums[i] == minK) jmin = i;
            if (nums[i] == maxK) jmax = i;
            cnt+=max(0, min(jmin, jmax)-jbad);
        }
        return cnt;
    }
};
