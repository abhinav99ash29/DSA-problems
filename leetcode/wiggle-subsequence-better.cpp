class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) { // an element can be only in 3 states, part of up sequence, down sequence or neither of them
        int n = nums.size(); // up captures the len of sequence ending with +ve difference and down captures length of sequence ending with negative difference
        if (n==1) return n;
        if (n==2) return nums[0]!=nums[1] ? 2 : 1;
        int up=1, down = 1;
        for(int i=0;i<n-1;i++) {
            int diff = nums[i+1]-nums[i];
            if (diff > 0) {
                up = down+1;
            }
            if (diff < 0) {
                down = up+1;
            }
        }
        return max(up, down);
    }
};
