class Solution {
public:
    
    int binarySearch(vector<int>& nums, int tar, int l, int r) {
        while(l<=r) {
            int mid = (l+r)/2;
            if (tar == nums[mid]) return mid;
            else if (tar > nums[mid]) {
                l = mid+1;
            } else r = mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1, mid = 0;
        while(l<r) {
            mid = (l+r)/2;
            if (nums[mid]>nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        int half1 = binarySearch(nums, target, 0, l-1);
        int half2 = binarySearch(nums, target, l, n-1);
        return max(half1, half2);
    }
};
