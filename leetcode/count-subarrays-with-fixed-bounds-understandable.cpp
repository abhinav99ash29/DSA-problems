class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        int n = nums.size();
        long long cnt = 0;
        int left = 0, mx = -1, mn = -1;
        for(int i=0;i<n;i++) {
            if (nums[i]<mink || nums[i]>maxk) {
                mx = -1;
                mn = -1;
                left = i+1;
            }
            if (nums[i]==mink) mn = i;
            if (nums[i]==maxk) mx = i;
            // cout<<left<<" "<<mn<<" "<<mx<<endl;
            if (mx!=-1 && mn!=-1) {
                cnt+=(min(mn,mx)-left+1);
            }
        }
        return cnt;
    }
};
