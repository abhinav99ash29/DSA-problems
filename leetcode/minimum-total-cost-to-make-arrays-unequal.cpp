class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long mx = 0, mxval = 0, swap = 0, ans = 0;
        int n = nums1.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++) {
            if (nums1[i]==nums2[i]) {
                ans+=i;
                swap++;
                m[nums1[i]]++;
                if (m[nums1[i]] > mx) {
                    mx = m[nums1[i]];
                    mxval = nums1[i];
                }
            }
        }
        for(int i=0;i<n;i++) {
            if (mx*2 > swap && nums1[i]!=nums2[i] && nums1[i]!=mxval && nums2[i]!=mxval) {
                ans+=i;
                swap++;
            }
        }
        if (mx*2 > swap) return -1;

        return ans;
    }
};
