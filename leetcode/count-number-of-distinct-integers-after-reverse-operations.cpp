class Solution {
public:
    
    int rev(int n) {
        int c = n;
        int ans = 0;
        while(c) {
            int d = c%10;
            ans = ans*10+d;
            c = c/10;
        }
        return ans;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        for(int i: nums) {
            st.insert(i);
            st.insert(rev(i));
        }
        return st.size();
    }
};
