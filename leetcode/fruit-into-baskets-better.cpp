class Solution {
public:
    int totalFruit(vector<int>& fr) {
        unordered_map<int, int> mp;
        int n = fr.size();
        int ans = 0;
        int i=0,j=0;
        while(j<n) {
            // cout<<i<<" "<<j<<endl;
            mp[fr[j]]++;
            while(mp.size()>2) {
                if (--mp[fr[i]]==0) mp.erase(fr[i]);
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
