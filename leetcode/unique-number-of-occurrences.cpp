class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i: arr) {
            mp[i]++;
        }
        set<int> st;
        for(auto& itr: mp) {
            if (st.count(itr.second)) return false;
            st.insert(itr.second);
        }
        return true;
    }
};
