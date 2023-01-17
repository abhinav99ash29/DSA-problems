class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> zr(n+1, 0), ol(n+1, 0);
        for(int i=1, j=n-1;i<=n && j>=0;i++,j--) {
            ol[i] = ol[i-1]+(s[i-1]=='1'?1:0); // ones at the left that need flipping
            zr[j] = zr[j+1]+(s[j]=='0'?1:0); // zeroes at the right that need flipping
        }
        int ans = INT_MAX;
        for(int i=0;i<=n;i++) {
            ans = min({ol[i]+zr[i], ans}); // find the correct boundary between ones and zeroes having minimum cost
        }
        return ans;
    }
};
