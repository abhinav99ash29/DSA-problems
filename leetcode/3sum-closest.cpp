class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sol = 0, mn = INT_MAX;
        for(int k=0;k<n;k++) {
            int i=k+1, j=n-1;
            int temp = target-nums[k];
            while(i<j) {
                if (mn>abs(target-(nums[i]+nums[j]+nums[k]))) {
                    mn = abs(target-(nums[i]+nums[j]+nums[k]));
                    sol = nums[i]+nums[j]+nums[k];
                }
                if (nums[i]+nums[j] > temp) j--;
                else i++;
            }
        }
        return sol;
    }
};
