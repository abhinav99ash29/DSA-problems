class Solution {
    map<vector<int>,bool> m;
public:
    void fn(int idx, vector<int>& nums, vector<int>& sub, vector<vector<int>>& res) {
        if (!m.count(sub)) {
            res.push_back(sub);
            m[sub] = true;
        }
        
        for(int i=idx;i<nums.size();i++) {
            sub.push_back(nums[i]);
            fn(i+1,nums,sub,res);
            sub.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> sub;
        fn(0,nums,sub,res);
        return res;
    }
};
