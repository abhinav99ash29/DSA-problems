class Solution {
    vector<vector<int>> ans;
public:
    
    void fn(vector<int>& nums, vector<int>& soFar) {
        int n = nums.size();
        
        if (soFar.size() == n) {
            ans.push_back(soFar);
            return;
        }
       
        for(int k=0;k<n;k++) {
            if (nums[k]==100) continue;
            if (k>0 && nums[k]==nums[k-1]) continue;
            soFar.push_back(nums[k]);
            int i = nums[k];
            nums[k]=100;
            fn(nums,soFar);
            soFar.pop_back();
            nums[k] = i;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> soFar;
        fn(nums,soFar);
        return ans;
    }
};
