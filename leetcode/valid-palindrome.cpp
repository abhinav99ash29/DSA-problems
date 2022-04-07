class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c: s) {
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                str+=c;
            } else if (c >= 'A' && c <= 'Z') {
                str+=tolower(c);
            }
        }
        string str1 = str;
        reverse(str.begin(), str.end());
        return str1.compare(str) == 0;
    }
};
