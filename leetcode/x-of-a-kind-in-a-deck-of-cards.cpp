class Solution {
public:
    
    int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b,a%b);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> mp;
        for(int& i: deck) {
            mp[i]++;
        }
        int prev = mp.begin()->second;
        for(auto& it: mp) {
            int gc = gcd(prev, it.second);
            if (gc<2) return false;
            prev = gc;
        }
        return true;
    }
};
