class Solution {
public:

    void fn(vector<int>& nums, int k, set<vector<int>>& st, vector<int>& sofar) {
        int n = nums.size();
        if (sofar.size()>1) st.insert(sofar);
        if (k>=n) return;
        if (sofar.size()==0 || sofar[sofar.size()-1] <= nums[k]) {
            sofar.push_back(nums[k]);
            fn(nums,k+1,st,sofar);
            sofar.pop_back();
        }
        if (sofar.size()==0 || sofar[sofar.size()-1]!=nums[k]) {
            fn(nums, k+1, st, sofar);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> sofar;
        set<vector<int>> st;
        fn(nums, 0, st, sofar);
        return vector(st.begin(), st.end());
    }
};
