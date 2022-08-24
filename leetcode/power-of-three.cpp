class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        double x = log2(n)/log2(3);
        int x1 = (int)x;
        // cout<<x<<" "<<x1<<" "<<ceil(x-x1)<<endl;
        if (x-x1 > 0.00000000001) return false;
        return true;
    }
};
