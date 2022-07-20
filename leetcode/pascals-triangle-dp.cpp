class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sol;
        sol.push_back({1});
        for(int i=1;i<numRows;i++) {
            sol.push_back(vector<int>(i+1,1));
            for(int j=1;j<i;j++) {
                sol[i][j] = sol[i-1][j-1]+sol[i-1][j];
            }
        }
        return sol;
    }
};
