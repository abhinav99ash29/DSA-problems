class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int sum = 0,l=0;
        int ans = 0;
        for(int r=0;r<nums.size();r++) {
            while (mp[nums[r]]) {
                mp[nums[l]] = false;
                sum-=nums[l];
                l++;
            }
            mp[nums[r]] = true;
            sum+=nums[r];
            ans = max(ans, sum);
        }
        return ans;
    }
};
