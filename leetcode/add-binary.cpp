class Solution {
public:
    string addBinary(string& a, string& b) {
        int i = a.size()-1, j = b.size()-1;
        bool carry = false;
        string ans = "";
        while(i>=0 && j>=0) {
            if (a[i]=='1' && b[j]=='1') {
                if (carry) {
                    ans = "1"+ans;
                } else {
                    ans = "0"+ans;
                    carry = true;
                }
            } else if (a[i]=='1' || b[j]=='1') {
                if (carry) {
                    ans = "0"+ans;
                    carry = true;
                } else {
                    ans = "1"+ans;
                }
            } else {
                if (carry) {
                    ans = "1"+ans;
                    carry = false;
                } else {
                    ans = "0"+ans;
                }
            }
            i--;
            j--;
        }
        while(i>=0) {
            if (a[i]=='1') {
                if (carry) {
                    ans = "0"+ans;
                    carry = true;
                } else {
                    ans = "1"+ans;
                }
            } else {
                if (carry) {
                    ans = "1"+ans;
                    carry = false;
                } else {
                    ans = "0"+ans;
                }
            }
            i--;
        }
        while(j>=0) {
            if (b[j]=='1') {
                if (carry) {
                    ans = "0"+ans;
                    carry = true;
                } else {
                    ans = "1"+ans;
                }
            } else {
                if (carry) {
                    ans = "1"+ans;
                    carry = false;
                } else {
                    ans = "0"+ans;
                }
            }
            j--;
        }
        if (carry) {
            ans = "1"+ans;
        }
        return ans;
    }
};
