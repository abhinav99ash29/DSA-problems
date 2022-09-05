class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, bool> mp;
        for(int i=0;i<n-1;i++) {
            int s = nums[i]+nums[i+1];
            if (mp.count(s)) return true;
            mp[s] = true;
        }
        return false;
    }
};
