class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        vector<int> b;
        while(k) {
            b.push_back(k%10);
            k/=10;
        }
        reverse(b.begin(), b.end());
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        vector<int> ans;
        while(i>=0 || j>=0 || carry) {
            if (i>=0) {
                carry+=a[i];
                i--;
            }
            if (j>=0) {
                carry+=b[j];
                j--;
            }
            ans.push_back(carry%10);
            carry/=10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
