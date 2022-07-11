class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 0;
        char prev = ' ';
        for(char&c: s) {
            if (c==prev) {
                if (cnt<2) {
                    ans+=c;
                    cnt++;
                } else {
                    continue;
                }
            } else {
                ans+=c;
                prev = c;
                cnt = 1;
            }
        }
        return ans;
    }
};
