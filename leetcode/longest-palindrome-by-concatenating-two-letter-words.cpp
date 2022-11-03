class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0, palin = 0;
        for(string& s: words) {
            mp[s]++;
        }
        for(string& s: words) {
            if (mp[s]==0) continue;
            if (s[0]==s[1]) {
                ans+=(mp[s]/2)*4;
                if (mp[s]%2==1) {
                    palin = 2;
                }
                mp[s] = 0;
            } else {
                string rev = "";
                rev.push_back(s[1]);
                rev.push_back(s[0]);
                ans+=min(mp[s],mp[rev])*4;
                mp[s] = 0;
                mp[rev] = 0;
            }
        }
        return ans+palin;
    }
};
