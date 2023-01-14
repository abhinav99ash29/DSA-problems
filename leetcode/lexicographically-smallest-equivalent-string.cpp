class Solution {
public:

    int find(int x, vector<int>& par) {
        while(par[x]!=-1) {
            x = par[x];
        }
        return x;
    }

    void un(int x, int y, vector<int>& par) {
        int rootx = find(x ,par);
        int rooty = find(y, par);
        if (rootx < rooty) {
            par[rooty] = rootx;
        }  else if(rootx > rooty) {
            par[rootx] = rooty;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        vector<int> par(26,-1);
        for(int i=0;i<n;i++) {
            un(s1[i]-'a', s2[i]-'a', par);
        }
        string ans = "";
        n = baseStr.size();
        for(int i=0;i<n;i++) {
           ans+=find(baseStr[i]-'a', par)+97;
        }
        return ans;
    }
};
