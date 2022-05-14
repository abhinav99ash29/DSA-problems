class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i=n-1;i>0;i--) {
            if (nums[i]>nums[i-1])
                break;
        }
        i--;
        if (i>=0) {
         int first = nums[i];
            int nextMin = INT_MAX;
            int nextIdx = -1;
            for(int j=n-1;j>i;j--) {
                if (first<nums[j] && nextMin>nums[j]) {
                    nextMin = nums[j];
                    nextIdx = j;
                }
            }
            if (nextIdx!=-1) {
                swap(nums[i],nums[nextIdx]);
                reverse(nums.begin()+i+1,nums.end());
                return;
            }   
        }
        sort(nums.begin(), nums.end());
    }
};
