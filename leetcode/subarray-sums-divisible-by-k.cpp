class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int m[k];
        memset(m,0,sizeof(m));
        int pref = 0;
        m[0]++;
        int ans = 0;
        for(int i=1;i<=n;i++) {
            pref=((nums[i-1] + pref)%k + k)%k;
            ans+=m[pref];
            m[pref]++;
        }
        return ans;
    }
};
