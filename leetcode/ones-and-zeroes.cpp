class Solution {
    vector<vector<vector<int>>> dp;
public:
    
    vector<int> cnt(string str) {
        int m = 0, n = 0;
        for(char c: str) {
            if (c=='0') m++;
            else n++;
        }
        return {m,n};
    }
    
    int fn(vector<vector<int>>& arr, int i, int rm, int rn) {
        int n = arr.size();
        if (i>=n) return 0;
        if (dp[i][rm][rn]!=-1) return dp[i][rm][rn];
        int ans = 0;
        if (rm>=arr[i][0] && rn>=arr[i][1]) {
            ans = 1 + fn(arr, i+1, rm-arr[i][0], rn-arr[i][1]);
        }
        return dp[i][rm][rn] = max(ans, fn(arr,i+1,rm,rn));
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> arr;
        dp.resize(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        for(string str: strs) {
            arr.push_back(cnt(str));
        }
        return fn(arr,0,m,n);
    }
};
