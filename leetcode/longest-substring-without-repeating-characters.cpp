class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        int res = 0;
        int i = 0, j = 0;
        vector<int> vis(256);
        while(i<n&&j<n) {
            vis[str[j]]++;
            if (vis[str[j]]>1) {
                while(vis[str[j]]>1&&i<n) {
                    vis[str[i]]--;
                    i++;
                }
            } else {
                if (res < (j-i+1)) {
                    res=j-i+1;
                }
            }
            j++;
        }
          
        return res;
    }
};

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
