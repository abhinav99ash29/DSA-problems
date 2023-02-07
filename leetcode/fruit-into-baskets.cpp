class Solution {
public:
    int totalFruit(vector<int>& fr) {
        unordered_map<int, int> mp;
        int n = fr.size();
        int ans = 0;
        int i=0,j=0;
        int cnt = 0;
        while(j<n) {
            // cout<<i<<" "<<j<<endl;
            if (mp[fr[j]] == 0) cnt++;
            mp[fr[j]]++;
            while(cnt>2) {
                mp[fr[i]]--;
                if (mp[fr[i]]==0) cnt--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
