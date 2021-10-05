class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, h=n-1, mid=0;
        while(l<=h) {
            mid=(l+h)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                l=mid+1;
            else
                h=mid-1;
        }
        return l;
    }
};
