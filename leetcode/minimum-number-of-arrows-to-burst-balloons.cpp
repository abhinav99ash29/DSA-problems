class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int s=points[0][0], e=points[0][1];
        int cnt = 1;
        for(vector<int> v: points) {
            if (v[0]>e) {
                cnt++;
                s=v[0];
                e=v[1];
            } else {
                s = max(s, v[0]);
                e = min(e, v[1]);
            }
        }
        return cnt;
    }
};
