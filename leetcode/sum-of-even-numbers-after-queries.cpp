class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) {
            if ((nums[i]&1) == 0) sum+=nums[i];
        }
        vector<int> sol;
        for(int i=0;i<queries.size();i++) {
            int val = queries[i][0];
            int idx = queries[i][1];
            if ((nums[idx]&1)==0) sum-=nums[idx];
            nums[idx] = nums[idx]+val;
            if ((nums[idx]&1)==0) sum+=nums[idx];
            sol.push_back(sum);
        }
        return sol;
    }
};
