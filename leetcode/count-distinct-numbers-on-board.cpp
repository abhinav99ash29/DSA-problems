class Solution {
public:
    int distinctIntegers(int n) {
        unordered_set<int> st;
        st.insert(n);
        int prev = -1;
        while(true) {
            for(auto& i: st) {
                for(int j=1;j<=n;j++) {
                    if (i%j == 1) st.insert(j);
                }
            }
            if (prev == st.size()) break;
            prev = st.size();
        }
        return st.size();
    }
};
