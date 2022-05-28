class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0, r=n;
        int mid=0;
        while(l<r) {
            mid = (l+r)/2;
            if (nums[mid]>mid) {
                r = mid;
            } else
                l = mid+1;
        }
        return l;
    }
};
