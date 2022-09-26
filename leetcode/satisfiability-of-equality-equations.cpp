class Solution {
    vector<int> par;
public:
    int find(int x) {
        while(par[x]!=x) {
            x = par[par[x]];
        }
        return x;
    }
    
    void union1(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        par[rooty] = rootx;
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        par.resize(256,0);
        for(int i=0;i<256;i++) par[i] = i;
        for(int i=0;i<n;i++) {
            string s = equations[i];
            if (s[1]=='=') union1(s[0],s[3]);
        }
        
        for(int i=0;i<n;i++) {
            string s = equations[i];
            if (s[1]=='!') {
                int rootx = find(s[0]);
                int rooty = find(s[3]);
                if (rootx==rooty) return false;
            }
        }
        return true;
    }
};
