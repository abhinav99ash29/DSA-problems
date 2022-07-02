class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxvdiff = 0, prev = 0;
        for(int& i: verticalCuts) {
            maxvdiff = max(maxvdiff, i-prev);
            prev = i;
        }
        maxvdiff = max(maxvdiff, w-prev);
        int maxhdiff = 0;
        prev = 0;
        for(int& i: horizontalCuts) {
            maxhdiff = max(maxhdiff, i-prev);
            prev = i;
        }
        maxhdiff = max(maxhdiff, h-prev);
        int mod = (int)1e9+7;
        long long int ans = (((long long int)maxvdiff)%mod * ((long long int)maxhdiff)%mod)%mod;
        return ans;
    }
};
