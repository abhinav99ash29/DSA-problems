class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, j = 0;
        int n = colors.size();
        int sol = 0;
        while(i<n && j<n) {
            int mx = 0;
            while(j<n && colors[i]==colors[j]) {
                sol+=neededTime[j];
                mx = max(mx, neededTime[j]);
                j++;
            }
            sol-=mx;
            i = j;
        }
        return sol;
    }
};
