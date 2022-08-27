class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sol = INT_MIN;
        for(int l=0;l<n;l++) {
            vector<int> sums(m, 0);
            for(int r=l;r<n;r++) {
                for(int i=0;i<m;i++) {
                    sums[i]+=matrix[i][r];
                }
                set<int> st;
                st.insert(0);
                int run = 0;
                for(int& sum: sums) {
                    run+=sum;
                    auto itr = st.lower_bound(run - k);
                    if (itr != st.end()) {
                        sol = max(sol, run-*itr);
                    }
                    st.insert(run);
                }
            }
        }
        return sol;
    }
};
