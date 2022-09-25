class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> lt(n,1), rt(n,1);
        for(int i=1;i<n;i++) {
            if (nums[i-1]>=nums[i]) {
                lt[i] = lt[i-1]+1;
            }
        }
        
        for(int i=n-2;i>=0;i--) {
            if (nums[i]<=nums[i+1]) {
                rt[i] = rt[i+1]+1;
            }
        }
        vector<int> sol;
        for(int i=k;i<(n-k);i++) {
            if (lt[i-1]>=k && rt[i+1]>=k) sol.push_back(i);
        }
        return sol;
    }
};
