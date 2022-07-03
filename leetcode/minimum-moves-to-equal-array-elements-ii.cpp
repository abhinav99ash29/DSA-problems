class Solution {
public:
    
    int find(vector<int>& nums, int k) {
        int sum = 0;
        int i = 0;
        while(i<nums.size()) {
            sum+=abs(nums[k]-nums[i]);
            i++;
        }
        return sum;
    }
    
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n%2!=0) {
            return find(nums,n/2);
        }
        return min(find(nums,n/2),find(nums,n/2-1));
    }
};
