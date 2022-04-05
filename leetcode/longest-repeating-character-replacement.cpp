class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, ans = 0;
        vector<int> freq(26,0);
        for(int right = 0;right<s.size();right++) {
            freq[s[right] - 'A']++;
            int mostfreqletter = *max_element(freq.begin(), freq.end());
            int letterstochange = (right-left+1) - mostfreqletter;
            if (letterstochange > k) {
                freq[s[left]-'A']--;
                left++;
            }
            ans = max(ans, (right-left+1));
        }
        return ans;
    }
};
