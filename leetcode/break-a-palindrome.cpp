class Solution {
public:
    string breakPalindrome(string pal) {
        int n = pal.size();
        if (n<=1) return "";
        for(char ch='a';ch<='z';ch++) {
            int i=0, j=n-1;
            while(i<j) {
                if (pal[i]!=ch) {
                    if (pal[i]<ch) {
                        pal[j] = ch;
                        return pal;
                    } else {
                        pal[i] = ch;
                        return pal;
                    }
                }
                i++;
                j--;
            }
            
        }
        return "";
    }
};
