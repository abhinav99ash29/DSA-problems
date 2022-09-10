class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t n1 = 0;
        bool last = n & 1<<31;
        n = n | 1<<31; 
        while(n) {
            n1 = n1 | (n & 1);
            n = n>>1;
            if (n) n1 = n1<<1;
        }
        if (!last) n1 = n1 ^ 1;
        return n1;
    }
};
