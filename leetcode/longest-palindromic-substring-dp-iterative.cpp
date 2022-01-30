class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n, false));
        int lt=0,rt=0;
        for(int i=0;i<n;i++)
            dp[i][i]=true; // since every char is palindrome in itself
        for(int i=0;i+1<n;i++) {
            if (s[i]==s[i+1]) {
                lt=i;rt=i+1;
                dp[i][i+1]=true; // checking if two adjacent chars are same or not
            }
        }
        for(int j=2;j<n;j++) {
            for(int i=0;i<=j;i++) {
                if (s[i]==s[j] && j-i+1>2 && !dp[i][j]) {
                    dp[i][j] = dp[i+1][j-1];
                    if (dp[i][j] && rt-lt < j-i) {
                        lt=i;rt=j;
                    }
                }
            }
        }
        string ans="";
        for(int i=lt;i<=rt;i++)
            ans+=s[i];
        return ans;
    }
};

// https://leetcode.com/problems/longest-palindromic-substring/
