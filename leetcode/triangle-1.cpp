class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n, INT_MAX), curr(n, INT_MAX);
        prev[0] = triangle[0][0];
        for(int i=1;i<n;i++) {
            for(int j=0;j<=i;j++) {
                if (j==0) curr[j] = prev[j] + triangle[i][j];
                else {
                    curr[j] = min(prev[j], prev[j-1]) + triangle[i][j];
                }
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
