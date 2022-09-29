class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> q;
        for(int& i: arr) {
            // cout<<abs(x-i)<<" "<<i<<endl;
            if (q.size()<k) {
                q.push({abs(x-i),i});
            } else {
                if (q.top().first <= abs(x-i)) continue;
                q.pop();
                q.push({abs(x-i),i});
            }
        }
        vector<int> sol;
        while(!q.empty()) {
            sol.push_back(q.top().second);
            q.pop();
        }
        sort(sol.begin(), sol.end());
        return sol;
    }
};
