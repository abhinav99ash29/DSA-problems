class Solution {
public:
    
    string fill(vector<string> curr, int sz, int mx) {
        string sol = "";
        int n = curr.size();
        int needed = mx-sz;
        for(int i=0;i<n;i++) {
            sol+=curr[i];
            if (i < n-1) {
                int spaces = n-i-1;
                int currsp = ceil((double)needed/spaces);
                string s(currsp,' ');
                sol+=s;
                needed-=currsp;
            }
        }
        return sol;
    }
    
    vector<string> fullJustify(vector<string>& words, int mx) {
        vector<string> curr;
        vector<string> sol;
        int sz = 0, sp = 0;
        for(string& w: words) {
            if (sz+sp+w.size() <= mx) {
                curr.push_back(w);
                sz+=w.size();
                sp++;
            } else {
                string s = fill(curr,sz,mx);
                string s1(mx-(s.size()), ' ');
                s+=s1;
                sol.push_back(s);
                curr.clear();
                curr.push_back(w);
                sz=w.size();
                sp=1;
            }
        }
        string s = fill(curr,sz,sz+(sp-1));
        string s1(mx-(s.size()), ' ');
        s+=s1;
        sol.push_back(s);
        return sol;
    }
};
