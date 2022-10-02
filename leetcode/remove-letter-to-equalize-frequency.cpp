class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        vector<int> w(26,0);
        for(int i=0;i<n;i++) {
            w[word[i]-'a']++;
        }
        for(int i=0;i<26;i++) {
            if (w[i]!=0) {
                int temp = w[i];
                w[i]--;
                map<int, int> mp;
                for(int j=0;j<26;j++) {
                    if(w[j]!=0) mp[w[j]]++;
                }
                if (mp.size()==1) return true;
                w[i] = temp;
            }
        }
        
        return false;
        
    }
};
