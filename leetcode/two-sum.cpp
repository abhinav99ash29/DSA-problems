class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, bool> seen1;
        map<int, int> seen2;
        for(int i=0;i<n;i++) {
            int x = target - nums[i];
            if (seen1[x]) {
                return {i, seen2[x]};
            }
            seen1[nums[i]] = true;
            seen2[nums[i]] = i;
        }
        return {0, 0};
    }
};

// https://leetcode.com/problems/two-sum/submissions/
