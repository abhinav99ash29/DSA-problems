class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left=0,right=n-1,lmax=0,rmax=0;
        int ans = 0;
        while(left<right) {
            if (height[left]<height[right]) {
                height[left]>=lmax ? lmax = height[left] : ans+=lmax-height[left];
                left++;
            } else {
                height[right]>=rmax ? rmax = height[right] : ans+=rmax-height[right];
                right--;
            }
        }
        return ans;
    }
};
