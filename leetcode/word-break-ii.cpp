class Solution {
public:
    
    vector<string> fn(string& s, int i, vector<string>& dict) {
        if (i>=s.size()) return {""};
        
        vector<string> ans;
        int n = s.size();
        for(string w: dict) {
            int l = w.size();
            if ((n-i)>=l && s.substr(i,l) == w) {
                string p = w + " ";
                vector<string> ans1 = fn(s, i+l, dict);
                for(string w1: ans1) {
                    if (w1 == "") {
                        ans.push_back(p.substr(0,p.size()-1));
                    } else {
                        string p1 = p;
                        p1+=w1;
                        ans.push_back(p1);   
                    }
                }
            }
        }
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return fn(s,0,wordDict);
    }
};
