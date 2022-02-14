class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) { 
        int n = nums.size();
        int count = 1;
        int ans=0;
        for(int i=1;i<n-1;i++) {
            if (nums[i]-nums[i-1]==nums[i+1]-nums[i]) {
                while(i<n-1 && nums[i]-nums[i-1]==nums[i+1]-nums[i]) {
                    count++;
                    i++;
                }
                count-=1;
                ans+=(count*(count+1))/2;
            } else {
                count = 1;
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/arithmetic-slices/
