class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n%2!=0) return {};
        sort(changed.begin(), changed.end(), greater<int>());
        map<int, int> mp;
        vector<int> sol;
        for(int& i: changed) {
            if (mp[i*2]>0) {
                sol.push_back(i);
                mp[i*2]--;
            } else {
                mp[i]++;
            }
        }
        if (sol.size()!=(n/2)) return {};
        return sol;
    }
};
