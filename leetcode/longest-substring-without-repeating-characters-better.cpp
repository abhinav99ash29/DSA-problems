class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(256, -1);
        int ans = 0;
        int i = 0, j = 0;
        
        while(i < s.size() && j < s.size()) {
            if (vis[s[j]] != -1) {
                i = max(i, vis[s[j]]+1);
            }
            vis[s[j]] = j;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
