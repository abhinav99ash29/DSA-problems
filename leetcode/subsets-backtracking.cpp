// https://leetcode.com/problems/subsets/

class Solution {
public:
    
    void backtrack(vector<int> curr, int first, int k, vector<int> nums) {
        if (curr.size() == k) {
            result.push_back(curr);
            return;
        }
        for(int i=first;i<nums.size();i++) {
            curr.push_back(nums[i]);
            backtrack(curr,i+1, k, nums);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        for(int i=0;i<=nums.size();i++) {
            backtrack(curr, 0, i, nums);
        }
        return result;
    }
    
private:
    vector<vector<int>> result;
};
