class Solution {
public:
    bool isPalindrome(int x) {
        long int d=0;
        long int n = x;
        while(x>0) {
            int c = x%10;
            d = d*10+c;
            x=x/10;
        }
        if (n==d) 
            return true;
        return false;
    }
};

// https://leetcode.com/problems/palindrome-number/
