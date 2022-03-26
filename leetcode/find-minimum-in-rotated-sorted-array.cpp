class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, mid = 0;
        while(l<r) {
            mid = (l+r)/2;
            if (nums[mid] > nums[r])
                l = mid+1;
            else
                r = mid;
        }
        return nums[l];
    }
};
