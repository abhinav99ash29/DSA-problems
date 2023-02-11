class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> radj(n), badj(n);
        for(vector<int>& v: redEdges) radj[v[0]].push_back(v[1]);
        for(vector<int>& v: blueEdges) badj[v[0]].push_back(v[1]);
        vector<int> ans(n, -1);
        queue<pair<int,bool>> q;
        q.push({0,false});
        q.push({0,true});
        vector<vector<int>> rvis(n ,vector<int>(n, false)), bvis(n ,vector<int>(n, false));
        int dis = 0;
        while(q.size()) {
            int sz = q.size();
            // cout<<endl;
            while(sz--) {
                pair<int, bool> p = q.front(); q.pop();
                int u = p.first;
                // cout<<u<<" ";
                if (ans[u]!=-1) ans[u] = min(ans[u], dis);
                else ans[u] = dis;
                ans[u] = min(ans[u], dis);
                if (!p.second) {
                    for(int& v: badj[u]) {
                        if (bvis[u][v]) continue;
                        bvis[u][v] = true;
                        q.push({v, true});
                    }
                } else {
                    for(int& v: radj[u]) {
                        if (rvis[u][v]) continue;
                        rvis[u][v] = true;
                        q.push({v, false});
                    }
                }
                
            }
            dis++;
        }
        return ans;
    }
};
