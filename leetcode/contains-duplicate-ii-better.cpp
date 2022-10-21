class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,bool> m;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if (m.count(nums[i])) return true;
            m[nums[i]] = true;
            if (m.size()>k) {
                m.erase(nums[i-k]);
            }
        }
        return false;
    }
};
