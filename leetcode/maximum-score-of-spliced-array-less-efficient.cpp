class Solution {
public:
    int sum(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        return sum;
    }
    
    int fn(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff(nums2);
        for(int i=0;i<n;i++) diff[i]-=nums1[i];
        int maxsf = 0, currsum = 0;
        for(int i=0;i<n;i++) {
            if (currsum+diff[i] >= diff[i]) {
                currsum+=diff[i];
                maxsf = max(maxsf, currsum);
            } else {
                currsum = diff[i];
                maxsf = max(maxsf, currsum);
            }
        }
        int sum1 = sum(nums1);
        return sum1+maxsf;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int maxsum = 0;
        maxsum = max(maxsum, fn(nums1, nums2));
        maxsum = max(maxsum, fn(nums2, nums1));
        return maxsum;
    }
};
