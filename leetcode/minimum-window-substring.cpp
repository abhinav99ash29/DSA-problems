class Solution {
    
    int getRequired(vector<int> tvec) {
        int req = 0;
        for(int i=0;i<tvec.size();i++) {
            if (tvec[i]!=0) req++;
        }
        return req;
    }
    
public:
    
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minlen = INT_MAX;
        string ans = "";
        
        vector<int> tvec(128,0);
        
        for(int i=0;i<m;i++) {
            tvec[t[i]]++;
        }
        
        int required = getRequired(tvec);
        int l=0,r=0,formed=0;
        vector<int> window(128,0);
        
        while(r<n) {
            window[s[r]]++;
            if (window[s[r]] == tvec[s[r]]) {
                formed++;
            }
            
            while(l<=r && formed == required) {
                if (r-l+1 < minlen) {
                    minlen = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
                window[s[l]]--;
                if (window[s[l]] < tvec[s[l]]) {
                    formed--;
                }
                l++;
            }
            
            r++;
        }
        return ans;
    }
};

