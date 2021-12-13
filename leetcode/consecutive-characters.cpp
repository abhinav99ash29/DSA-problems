class Solution {
public:
    int maxPower(string s) {
        int cnt=1;
        int ans=1;
        char prev='/0';
        
        for(auto c: s) {
            if (c==prev) {
                cnt++;
                ans=max(ans,cnt);
            } else {
                cnt=1;
                prev=c;
            }
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/consecutive-characters/
