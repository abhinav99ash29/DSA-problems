class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int need = 1<<k;
        vector<bool> seen(need, false);
        int allone = need-1;
        int hash = 0;
        
        for(int i=0;i<n;i++) {
            hash = (hash<<1 & allone) | (s[i]-'0');
            if (i>=k-1 && !seen[hash]) {
                seen[hash] = true;
                need--;
                if (need == 0)
                    return true;
            }
        }
         return false;
    }
};
