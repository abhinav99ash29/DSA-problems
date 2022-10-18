class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        int k = votes[0].size();
        vector<vector<int>> arr(26, vector<int>(k+1,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                arr[votes[i][j]-'A'][j]++;
                arr[votes[i][j]-'A'][k] = votes[i][j]-'A';
            }
        }
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
           for(int i=0;i<a.size()-1;i++) {
               if (a[i]!=b[i])
                   return a[i]>b[i];
           }
           return a[a.size()-1]<b[a.size()-1];
        });
        string sol = "";
        for(int i=0;i<arr.size();i++) {
            bool allz = true;
            for(int j=0;j<k;j++) {
                if (arr[i][j]!=0) {
                    allz = false;
                    break;
                }
            }
            if (!allz) {
                sol+=arr[i][k]+'A';
            } else
                break;
        }
        return sol;
    }
};
