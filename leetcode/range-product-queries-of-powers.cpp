class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powr;
        int n1 = n;
        while(n1) {
            if (n1%2==0) {
                powr.push_back(0);
            }
            else {
                powr.push_back(1);
            }
            n1/=2;
        }
        vector<int> powers;
        for(int i=0;i<powr.size();i++) {
            if (powr[i]==1) {
                powers.push_back(pow(2,i));
            }
        }
        int mod = 1000000007;
        vector<int> sol;
        for(int i=0;i<queries.size();i++) {
            long long ans = 1;
            int left = queries[i][0], right = queries[i][1];
            for(int j=left;j<=right;j++) {
                ans = (ans%mod * powers[j]%mod)%mod;
            }
            sol.push_back(ans);
        }
        return sol;
    }
};
