class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> prev(n,0), curr(n,0);
       
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    curr[j] = matrix[i][j] - '0';
                } else {
                    curr[j] = min({prev[j],curr[j-1],prev[j-1]})+1;
                }
                ans = max(curr[j], ans);
            }
            prev = curr;
        }
        
        return ans*ans;
    }
};
