class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        int x = high-low+1;
        if (low%2) {
            ans = x/2 + (x%2 ? 1 : 0);
        } else {
            ans = x/2;
        }
        return ans;
    }
};
