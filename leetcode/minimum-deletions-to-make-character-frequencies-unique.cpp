class Solution {
public:
    int minDeletions(string s) {
        vector<int> fr(26,0);
        int sum = 0;
        for(char& c: s) fr[c-'a']++;
        sort(fr.begin(),fr.end(),greater<int>());
        int i;
        for(i=1;i<26;i++) {
            if (!fr[i]) break;
            if (fr[i] && fr[i]==fr[i-1]) {
                fr[i]-=1;
                sum+=1;
            } else if (fr[i]>fr[i-1]) {
                if (fr[i-1]==0) sum+=max(0,fr[i]-fr[i-1]);
                else sum+=max(0,fr[i]-fr[i-1]+1);
                fr[i] = max(0,fr[i-1]-1);
            }
        }
        return sum;
    }
};
