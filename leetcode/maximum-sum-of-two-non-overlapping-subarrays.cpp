class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> pref(n+1, 0);
        for(int i=1;i<=n;i++) {
            pref[i]+=pref[i-1]+nums[i-1];
        }
        
        return max(sum(pref, firstLen, secondLen), sum(pref, secondLen, firstLen));
    }
    
    int sum(vector<int> &pref, int l, int m) {
        int maxl = INT_MIN;
        int maxm = INT_MIN;
        int ans = INT_MIN;
        for(int i=l+m;i<pref.size();i++) {
            maxl = max(maxl, pref[i-m]-pref[i-m-l]);
            maxm = pref[i]-pref[i-m];
            ans = max(ans, maxl+maxm);
        }
        return ans;
    }
    
};
