class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, ans = 0;
        vector<int> a(26,0);
        int maxfreq = 0;
        for(int j=0;j<s.size();j++) {
            maxfreq = max(maxfreq, ++a[s[j]-'A']);
            if (((j-i+1)-maxfreq)>k) {
                a[s[i]-'A']--;
                i++;
            }
            ans = max(ans, (j-i+1));
        }
        return ans;
    }
};
