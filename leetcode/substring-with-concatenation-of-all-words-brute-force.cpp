class Solution {
public:
    bool check(string s, int i, vector<string>& words, vector<bool>& vis, int cnt, map<int, bool>& dp) {
        if (i==s.size()) return cnt == words.size();
        if (i>s.size()) return false;
        if (dp.count(i)>0) return dp[i];
        for(int k=0;k<words.size();k++) {
            if (!vis[k] && s.substr(i,words[k].size())==words[k]) {
                vis[k] = true;
                if(check(s,i+words[k].size(),words,vis,cnt+1,dp)) return dp[i] = true;
                break;
            }
        }
        return dp[i] = false;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> sol;
        int sz = 0;
        for(auto& w: words) sz+=w.size();
        string s1 = "";
        for(int i=0;i<min(sz,(int)s.size());i++) s1+=s[i];
        vector<bool> vis(words.size(), false);
        map<int, bool> dp;
        map<string, bool> mp;
        if (check(s1,0,words,vis,0,dp)) {
            mp[s1] = true;
            sol.push_back(0);
        } else mp[s1] = false;
        for(int i=sz;i<s.size();i++) {
            fill(vis.begin(), vis.end(), false);
            dp.clear();
            s1.erase(0,1);
            s1+=s[i];
            if (mp.count(s1)>0) {
                if (mp[s1]) {
                    sol.push_back(i-sz+1);
                }
                continue;
            }  
            if (check(s1,0,words,vis,0,dp)) {
                mp[s1] = true;
                sol.push_back(i-sz+1);
            } else {
                mp[s1] = false;
            }
        }
        return sol;
    }
};
