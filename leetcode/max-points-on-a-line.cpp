class Solution {
public:
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        unordered_map<double, int> mp;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (i==j) continue;
               int dx = points[i][0]-points[j][0];
               int dy = points[i][1]-points[j][1];
               if (dx==0) {
                   mp[INT_MAX]++;
                   ans = max(ans, mp[INT_MAX]+1);
                   continue;
               }
               mp[(double)dy/dx]++;
               ans = max(ans,  mp[(double)dy/dx]+1);
            }
            mp.clear();
        }
        return ans;
    }
};
