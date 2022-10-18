class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        int k = votes[0].size();
        vector<vector<int>> arr(26, vector<int>(27,0));
        for(int i=0;i<k;i++) arr[votes[0][i]-'A'][26] = votes[0][i];
        for(string& vote: votes) {
            for(int j=0;j<k;j++) {
                arr[vote[j]-'A'][j]--;
            }
        }
        sort(arr.begin(), arr.end());
        string sol = "";
        for(int i=0;i<26;i++) {
            if (arr[i][26])
            sol+=arr[i][26];
        }
        return sol;
    }
};
