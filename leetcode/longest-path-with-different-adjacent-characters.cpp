class Solution {
public:

    int fn(int v, vector<vector<int>>& child, string& s, int& mx) {
        int l = 0, r = 0;
        for(int i=0;i<child[v].size();i++) {
            int x = child[v][i];
            int f = fn(x,child,s,mx);
            if (s[v] == s[x]) continue;
            if (l<f) {
                r = l;
                l = f;
            } else if (r<f) {
                r = f;
            }
        }
        mx = max(mx, 1+l+r);
        return 1+l;
    }


    int longestPath(vector<int>& par, string s) {
        int mx = 1;
        int n = par.size();
        vector<vector<int>> child(n);
        for(int i=1;i<n;i++) {
            child[par[i]].push_back(i);
        }
        fn(0,child, s, mx);
        return mx;
    }
};
