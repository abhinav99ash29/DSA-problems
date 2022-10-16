class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, bool> mp;
        int mx = INT_MIN;
        for(int i: nums) {
            if (i>0 && mp.count(-i)) {
                mx = max(mx, i);
            }
            mp[i] = true;
        }
        return mx==INT_MIN ? -1 : mx;
    }
};
