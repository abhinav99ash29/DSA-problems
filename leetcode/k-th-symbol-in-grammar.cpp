class Solution {
public:
    // if k is even the parent's value is flipped otherwise it remains the same
    int fn(int n, int k) {
        if (n==1) return -1;
        if (k%2 != 0) {
            int x = k/2 + 1;
            return 1*fn(n-1,x);
        }
        return -1*fn(n-1,k/2);
    }
    
    int kthGrammar(int n, int k) {
        int ans = fn(n,k);
        if (ans == -1) return 0;
        return 1;
    }
};
