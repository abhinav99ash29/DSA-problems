class Solution {
public:
    int dist(string &a, string &b) {
        if (a==b) return 0;
        int cnt = 0;
        for(int i=0;i<8;i++) {
            if (a[i]!=b[i]) cnt++;
        }
        return cnt;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        bank.insert(bank.begin(),start);
        int endidx = -1;
        auto it = find(bank.begin(),bank.end(),end);
        if (it==bank.end()) return -1;
        else endidx = distance(bank.begin(),it);
        int n = bank.size();
        vector<vector<int>> arr(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int d = dist(bank[i],bank[j]);
                arr[i][j] = d>1 ? INT_MAX : d;
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) {
                    if (arr[i][k]==INT_MAX || arr[k][j]==INT_MAX) continue;
                    if (arr[i][j] > (arr[i][k]+arr[k][j])) {
                        arr[i][j] = arr[i][k]+arr[k][j];
                    }
                }
            }
        }
        return arr[0][endidx]==INT_MAX ? -1 : arr[0][endidx];
    }
};
