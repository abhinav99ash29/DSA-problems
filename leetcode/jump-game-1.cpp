class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last = n-1;
        for(int i=n-2;i>=0;i--) {
            if (nums[i]+i>=last) {
                last = i; // updating the last position that needs to be reached to reach the end
            }
            if (last == 0) {
                return true;
            }
        }
        return n==1 ? true : false;
    }
};
