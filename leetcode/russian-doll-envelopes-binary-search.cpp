class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(), env.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        vector<int> ans;
        
        ans.push_back(env[0][1]);
        int idx=0;
        
        for(int i=1;i<n;i++) {
            if (ans[idx]<env[i][1]) {
                ans.push_back(env[i][1]);
                idx++;
            } else {
             int lb = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();  
             ans[lb] = env[i][1];    
            }
        }
        
        return ans.size();
    }
};
