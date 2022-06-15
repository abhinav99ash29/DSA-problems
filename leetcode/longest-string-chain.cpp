class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& s1, string& s2) {
            return s1.size()<s2.size();
        });
        unordered_map<string, int> dp;
        for(string s: words) dp[s] = 1;
        for(string s: words) {
            string s1 = s;
            for(auto itr=s1.begin();itr!=s1.end();itr++) {
                s1.erase(itr);
                if (dp.count(s1)) {
                    dp[s] = max(dp[s], 1+dp[s1]);
                }
                s1 = s;
            }
        }
        int ans = INT_MIN;
        for(auto i: dp) {
            ans = max(ans, i.second);
        }
        return ans;
    }
};
