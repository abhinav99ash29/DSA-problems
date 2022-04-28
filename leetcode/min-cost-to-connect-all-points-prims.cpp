class Solution {
public:
    int findMin(vector<int> &key, vector<bool> &vis) {
        int min = INT_MAX, idx = -1;
        for(int i=0;i<key.size();i++) {
            if (min>key[i] && !vis[i]) {
                min = key[i];
                idx = i;
            }
        }
        return idx;
    }
    
    int findSum(vector<int> & key) {
        int sum = 0;
        for(int i=0;i<key.size();i++) {
            sum += key[i];
        }
        return sum;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> key(n, INT_MAX);
        vector<bool> vis(n, false);
        set<int> mst;
        key[0] = 0;
        while(mst.size() < n) {
            int midx = findMin(key, vis);
            mst.insert(midx);
            vis[midx] = true;
            for(int i=0;i<n;i++) {
                if (i!=midx && !vis[i]) {
                    int x = abs(points[i][0]-points[midx][0])+abs(points[i][1]-points[midx][1]);
                    key[i] = min(key[i],x);
                }
            }
        }
        return findSum(key);
    }
};
