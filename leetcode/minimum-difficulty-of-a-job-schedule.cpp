class Solution {
public:
    int fn(int idx, int d, vector<int>& job, vector<vector<int>>& dp) {
        if (job.size()-idx < d) return 10005;
        if (idx==job.size()) return d==0 ? 0 : 10005;
        if (dp[idx][d]!=-1) return dp[idx][d];
        int mx = 0, sol = 10005;
        for(int i=idx;i<job.size();i++) {
            mx = max(mx, job[i]);
            sol = min(sol, mx+fn(i+1,d-1,job,dp));
        }
        return dp[idx][d] = sol;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d+1,-1));
        int ans = fn(0,d,jobDifficulty,dp);
        return ans>=10005 ? -1 : ans;
    }
};
