class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int cnt = 0;
        int right = -1;
        for(int i=0;i<n;i++) {
            right = max(right, flips[i]);
            if (right == i+1) { // meaning that right most lighted bulb is ith bulb, in i steps if ith bulb is the right most 1 then it means that all bulbs at the left are on, since bulbs are flipping from 0 to 1 only
                ++cnt;
            }
        }
        return cnt;
    }
};
