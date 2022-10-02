class Solution {
public:
    
    int findBits(int n) {
        int cnt = 0;
        while(n) {
            if(n&1) cnt++;
            n = n>>1;
        }
        return cnt;
    }
    
    int minimizeXor(int nums1, int nums2) {
        vector<bool> v(32,0);
        int k=0;
        while(nums1) {
            if(nums1&1) {
                v[k]=true;
            }
            k++;
            nums1 = nums1>>1;
        }
        int n = findBits(nums2);
        int sol = 0;
        for(int i=31;i>=0 && n>0;i--) {
            if(v[i]) {
                sol+=pow(2,i);
                n--;
            }
        }
        if(n>0) {
            for(int i=0;i<32 && n>0;i++) {
                if(!v[i]) {
                    sol+=pow(2,i);
                    n--;
                }
            } 
        }
        return sol;
    }
};
