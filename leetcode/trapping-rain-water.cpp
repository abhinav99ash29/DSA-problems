class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMx(n), rightMx(n);
        leftMx[0] = height[0];
        rightMx[n-1] = height[n-1];
        for(int i=1;i<n;i++) {
            leftMx[i] = max(leftMx[i-1], height[i]);
        }
        for(int i=n-2;i>=0;i--) {
            rightMx[i] = max(rightMx[i+1], height[i]);
        }
        int ans = 0;
        for(int i=1;i<n-1;i++) {
            ans+=min(leftMx[i], rightMx[i]) - height[i];
        }
        return ans;
    }
};
