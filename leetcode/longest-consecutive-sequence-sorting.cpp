class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1, cnt = 1;
        int prev = nums[0];
        for(int i=1;i<n;i++) {
            if (nums[i] == prev+1) {
                cnt++;
                while(i<n && nums[i]==prev+1) 
                    i++;
                i--;
                ans = max(cnt, ans);
            } else {
                cnt=1;
            }
            if (i<n)
            prev = nums[i];
        }
        return ans;
    }
};
