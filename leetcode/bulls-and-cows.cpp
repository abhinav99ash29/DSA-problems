class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> mp(10,0);
        for(char& c: guess) mp[c-'0']++;
        int bcnt = 0, ccnt = 0;
        for(int i=0;i<n;i++) {
            if (secret[i]==guess[i]) {
                bcnt++;
                mp[secret[i]-'0']--;
            }
        }
        
        for(int i=0;i<n;i++) {
            if (secret[i]!=guess[i] && mp[secret[i]-'0']>0) {
                ccnt++;
                mp[secret[i]-'0']--;
            }
        }
        
        string sol = to_string(bcnt)+'A'+to_string(ccnt)+'B';
        return sol;
    }
};
