class Solution {
public:
    bool check(vector<int> &v, vector<bool> &vis, int curr, int n) {
        if (n==v.size()) {
            // cout<<curr<<endl;
            double lg = log2(curr);
            return lg-(int)lg == 0;
        }
        
        for(int i=0;i<v.size();i++) {
            if (curr==0 && v[i]==0) continue;
            if (!vis[i]) {
                vis[i] = true;
                if (check(v,vis,curr*10+v[i],n+1)) return true;
                vis[i] = false;
            }
        }
        
        return false;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> v;
        int d = n;
        while(d) {
            v.push_back(d%10);
            d/=10;
        }
        reverse(v.begin(), v.end());
        vector<bool> vis(v.size(), false);
        return check(v,vis,0,0);
        
    }
};
