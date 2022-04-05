class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        int distance = 0;
        for(int i=0;i<=distance;i++) {
            distance = max(distance, nums[i]+i);
            if (distance >= nums.size()-1) {
                return true;
            }
        }
        return false;
    }
};

