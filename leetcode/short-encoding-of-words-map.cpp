class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& s1, string& s2){
            return s1.size()>s2.size();
        });
        unordered_map<string, int> mp;
        for(string& s: words) mp[s]++;
        
        int ans = 0;
        for(string& s: words) {
            if (mp[s]>0) {
                ans+=(s.size()+1);
            }
            string s1 = "";
            for(int j = s.size()-1;j>=0;j--) {
                s1=s[j]+s1;
                mp[s1] = 0;
            }
        }
        return ans;
    }
};
