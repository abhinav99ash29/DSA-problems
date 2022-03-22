class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int k=0;k<n;k++) {
            int start = k+1, end = n-1;
            while(start < end) {
                if (nums[k]+nums[start]+nums[end] == 0) {
                    vector<int> temp = {nums[k],nums[start],nums[end]};
                    ans.push_back(temp);
                    while(start <n && nums[start] == temp[1])
                    start++;
                } else if (nums[k]+nums[start]+nums[end] > 0) {
                    end--;
                } else {
                    start++;
                }
            }
            while(k+1<n && nums[k] == nums[k+1])
                k++;
        }
        return ans;
    }
};
