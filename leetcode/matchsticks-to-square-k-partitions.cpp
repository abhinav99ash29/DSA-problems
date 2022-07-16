class Solution {
    bool ans;
public:
    
    
    void fn(int target, vector<bool>&vis, int k, int curr, vector<int>& match, int start) {
        if (curr == target) {
            k--;
            curr = 0;
            start = 0;
        }
        if (k==1 || ans) {
            ans = true;
            return;
        }
        for(int i=start;i<vis.size();i++) {
            if (!vis[i] && curr+match[i]<=target) {
                if (k==1 || ans) return;
                vis[i] = true;
                fn(target, vis, k, curr+match[i],match,i+1);
                vis[i] = false;
            }
        }
    }
    
    bool makesquare(vector<int>& match) {
        
        int sum = accumulate(match.begin(), match.end(), 0);
        if (sum%4!=0) return false;
        ans = false;
        vector<bool> vis(match.size(), false);
        fn(sum/4,vis,4,0,match,0);
        return ans;
    }
};
