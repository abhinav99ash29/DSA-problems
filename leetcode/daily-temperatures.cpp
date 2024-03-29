class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        for(int i=0;i<n;i++) {
            while(st.size() && temp[i]>st.top().first) {
                ans[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({temp[i],i});
        }
        return ans;
    }
};
