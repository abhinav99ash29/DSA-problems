class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        vector<int> sub;
        for(int n: nums) {
            if (sub.size()==0||sub[sub.size()-1]<n) {
                sub.push_back(n);
            } else {
                auto itr = lower_bound(sub.begin(), sub.end(), n);
                *itr = n;
            }
        }
        return sub.size();
    }
};
