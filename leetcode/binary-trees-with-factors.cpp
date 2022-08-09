class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = (int)1e9+7;
        int n = arr.size();
        map<int, int> dp;
        map<int, bool> vis;
        sort(arr.begin(), arr.end());
        vis[arr[0]] = true;
        dp[arr[0]] = 1;
        for(int i=1;i<n;i++) {
            int x = arr[i];
            vis[x] = true;
            dp[x] = 1;
            for(int j=0;j<i;j++) {
                if (x%arr[j]==0 && vis.count(x/arr[j])>0) {
                    long int temp = ((long int)dp[arr[j]]%mod * (long int)dp[x/arr[j]]%mod)%mod;
                    dp[x] = (dp[x]%mod + temp)%mod;
                }
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++) {
            // cout<<arr[i]<<" "<<dp[arr[i]]<<endl;
            sum = (sum%mod + dp[arr[i]]%mod)%mod;
        }
        return sum;
    }
};
