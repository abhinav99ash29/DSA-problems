class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int maxlen = -1;
        int i=0,j=0;
        int sum = 0;
        for(int p: nums) sum+=p;
        sum-=x;
        int subsum = 0;
        while(j<n) {
            subsum+=nums[j];
            while(i<=j && subsum > sum) {
                subsum-=nums[i++];
            }
            if (subsum == sum) {
                maxlen = max(maxlen, (j-i+1));
            }
            j++;
        }
        return maxlen == -1 ? -1 : n-maxlen;
    }
};
