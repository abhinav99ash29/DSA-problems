class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int mp[10];
        memset(mp, 0, 10*sizeof(mp[0]));
        int bcnt = 0, ccnt = 0;
        for(int i=0;i<n;i++) {
            char s = secret[i]-'0', g = guess[i]-'0';
            if (s==g) bcnt++;
            else {
                if (mp[s]<0) ccnt++;
                if (mp[g]>0) ccnt++;
                mp[s]++;
                mp[g]--;
            }
        }
        
        return to_string(bcnt) + "A" + to_string(ccnt) + "B";
    }
};
