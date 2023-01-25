class Solution {
public:
    void fn(int i, int d, vector<vector<int>>& dis, vector<bool>& vis, vector<int>& edges, int nod) {
        vis[i] = true;
        dis[i][nod] = d;
        if(edges[i]!=-1 && !vis[edges[i]]) {
            fn(edges[i],d+1,dis,vis,edges,nod);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> vis(n, false);
        vector<vector<int>> dis(n, {INT_MAX, INT_MAX});
        fn(node1, 0, dis, vis, edges, 0);
        fill(vis.begin(), vis.end(), false);
        fn(node2, 0, dis, vis, edges, 1);
        int mn = INT_MAX;
        int ans = -1;
        for(int i=0;i<n;i++) {
            // cout<<dis[i][0]<<", "<<dis[i][1]<<"   ";
            if (mn>max(dis[i][0], dis[i][1])) {
                mn = max(dis[i][0], dis[i][1]);
                ans = i;
            }
        }
        // cout<<endl;
        return ans;
    }
};
