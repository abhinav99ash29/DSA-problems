class Solution {
    set<vector<int>> ans;
public:
    
    void fn(vector<int>& nums, vector<int>& vis, vector<int>& soFar) {
        int n = nums.size();
        if (soFar.size() == n) {
            ans.insert(soFar);
            return;
        }
       
        for(int k=0;k<n;k++) {
            if (!vis[k]) {
                vis[k] = true;
                soFar.push_back(nums[k]);
                fn(nums,vis,soFar);
                soFar.pop_back();
                vis[k] = false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n,false);
        vector<int> soFar;
        fn(nums,vis,soFar);
        vector<vector<int>> ans1;
        for(auto i: ans) {
            ans1.push_back(i);
        }
        return ans1;
    }
};
