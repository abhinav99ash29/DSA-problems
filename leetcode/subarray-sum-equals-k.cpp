class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sol = 0, run=0;
        map<int, int> mp;
        mp[0] = 1;
        for(int i=0;i<n;i++) {
            run+=nums[i];
            if (mp.count(run-k)) sol+=mp[run-k];
            mp[run]++;
        }
        return sol;
    }
};
