class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<=0) return false;
        if (n==1) return true;
        double lgd = (double)log2(n);
        int lg = (int)lgd;
        if (lgd-lg > 0) return false;
        return lg%2==0;
    }
};
