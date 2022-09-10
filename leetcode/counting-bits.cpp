class Solution {
public:
    int fn(int i, map<int,int>& mp) {
        if (mp.count(i)) return mp[i];
        return mp[i] = (i%2)+fn(i/2,mp);
    }
    
    vector<int> countBits(int n) {
        map<int, int> mp;
        mp[0] = 0;
        mp[1] = 1;
        vector<int> sol;
        for(int i=0;i<=n;i++) {
            sol.push_back(fn(i,mp));
        }
        return sol;
    }
};
