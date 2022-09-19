class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n%2!=0) return {};
        unordered_map<int, int> m;
        for(int&i: changed) m[i]++;
        vector<int> keys,sol;
        for(auto& it: m) keys.push_back(it.first);
        sort(keys.begin(), keys.end());
        for(int& x: keys) {
            if (m[x]>m[2*x]) return {};
            for(int i=0;i<m[x];i++,m[x*2]--) {
                sol.push_back(x);
            }
        }
        return sol;
    }
};
