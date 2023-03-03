class Solution {
public:
    int strStr(string ha, string ne) {
        int m = ha.size(), n = ne.size();
        int i = 0, j = 0;
        int ans = 0;
        while(i<m && j<n) {
            if (ha[i++] == ne[j]) {
                j++;
            } else {
                i = i-j;
                j = 0;
                ans = i;
            }
        }
        return j==n ? ans : -1;
    }
};
