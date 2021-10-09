class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int x = k%n;
        if (x>0) {
            vector<int> ans;
        int i=n-x;
        while(i<n) {
            ans.push_back(nums[i]);
            i++;
        }
        i=0;
        while(i<(n-x)) {
            ans.push_back(nums[i]);
            i++;
        }
        i=0;
        while(i<n) {
            nums[i] = ans[i];
            i++;
        }
    }  
    }
};
