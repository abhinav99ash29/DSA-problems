class Solution {
    unordered_map<string, bool> dp;
public:
    
    bool fn(string s, vector<string>& wordDict) {
        if (s.size() == 0) return true;
        if (dp.find(s)!=dp.end()) return dp[s];
        
        bool x = false;
        for(int i=0;i<wordDict.size();i++) {
            int wl = wordDict[i].size();
            if (wl <= s.size() && wordDict[i] == s.substr(0,wl)) {
                string rem = s.substr(wl);
                x = x || fn(rem, wordDict);
                if (x) break;
            }
        }
        return dp[s] = x;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return fn(s, wordDict);
    }
};
