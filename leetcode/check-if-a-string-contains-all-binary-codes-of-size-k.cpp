class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        string s1 = s.substr(0,k);
        unordered_map<string, bool> mp;
        mp[s1] = true;
        for(int i=1;i<n-k+1;i++) {
            s1.push_back(s[i+k-1]);
            s1.erase(0,1);
            // cout<<s1<<endl;
            mp[s1] = true;
        }
        if (mp.size()==pow(2,k))
        return true;
        
        return false;
    }
};
