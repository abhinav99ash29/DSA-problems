class Solution {
public:
    int minAreaRect(vector<vector<int>>& pt) {
        int n = pt.size();
        int ans = INT_MAX;
        unordered_map<int, bool> mp;
        for(vector<int>& v: pt) {
            mp[v[0]*40001+v[1]] = true;
        }
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if (pt[i][1]!=pt[j][1] && pt[i][0]!=pt[j][0]
                    && mp.count(pt[i][0]*40001+pt[j][1]) && mp.count(pt[j][0]*40001+pt[i][1])) {
                    ans = min(ans, abs(pt[i][0]-pt[j][0])*abs(pt[i][1]-pt[j][1]));
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
