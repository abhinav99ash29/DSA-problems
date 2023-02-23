class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& pr, vector<int>& cap) {
        int n = pr.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            v.push_back({cap[i], pr[i]});
        }
        sort(v.begin(), v.end());
        int i = 0;
        priority_queue<int> q;
        while(k--) {
            while(i<n && v[i].first<=w) {
                q.push(v[i].second);
                i++;
            }
            if (q.size()==0) break;
            w+=q.top();
            q.pop();
        }
        return w;
    }
};
