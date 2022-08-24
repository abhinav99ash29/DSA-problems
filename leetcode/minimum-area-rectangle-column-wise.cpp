class Solution {
public:
    int minAreaRect(vector<vector<int>>& pt) {
        int n = pt.size();
        int ans = INT_MAX;
        map<int, vector<int>> mp;
        for(vector<int>& v: pt) {
            mp[v[0]].push_back(v[1]);
        }
        
        map<int, int> lastx;
        for(auto& it: mp) {
            int x = it.first;
            vector<int> row = it.second;
            sort(row.begin(), row.end());
            for(int i=0;i<row.size();i++) {
                for(int j=i+1;j<row.size();j++) {
                    int y1 = row[i], y2 = row[j];
                    int cd = 40001*y1+y2;
                    if (lastx.count(cd))
                        ans = min(ans, (x-lastx[cd])*(y2-y1));
                    lastx[cd] = x;
                }
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};
