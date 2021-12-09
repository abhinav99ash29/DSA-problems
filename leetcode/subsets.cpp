// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = pow(2,n);
        for(int k=0;k<total;k++) {
            vector<int> ans;
            for(int i=0;i<n;i++) {
                if(k&(1<<i)) {
                    ans.push_back(nums[i]);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
    
private:
    vector<vector<int>> result;
};
