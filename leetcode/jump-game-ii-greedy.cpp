class Solution {
public:
    int jump(vector<int>& nums) {
        int currend=0,currfarthest=0,jumps=0;
        for(int i=0;i<nums.size()-1;i++) {
            currfarthest = max(currfarthest, i+nums[i]);
            if (i==currend) {
                jumps++;
                currend=currfarthest;
            }
        }
        return jumps;
    }
};
