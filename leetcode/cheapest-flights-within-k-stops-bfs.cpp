class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<flights.size();i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        int hops = 0;
        while(!q.empty()) {
            if (hops>k) break;
            int sz = q.size();
            while(sz--) {
                pair<int, int> p = q.front(); q.pop();
                int parent = p.first;
                int parentDis = p.second;
                for(int i=0;i<adj[parent].size();i++) {
                    pair<int, int> c = adj[parent][i];
                    int child = c.first;
                    int parentChildDis = c.second;
                    if (dis[child] > parentDis + parentChildDis) {
                        dis[child] = parentDis + parentChildDis;
                        q.push({child, dis[child]});
                    }
                }
            }
            hops++;
        }
        return dis[dst] == INT_MAX ? -1 : dis[dst];  
    }
};
