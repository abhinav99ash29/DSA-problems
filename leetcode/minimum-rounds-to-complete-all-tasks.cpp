class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(int& i: tasks) m[i]++;
        int ans = 0;
        for(auto& itr: m) {
            int x = itr.second;
            if (x==1) return -1;
            ans+=(x+2)/3;
        }
        return ans;
    }
};
