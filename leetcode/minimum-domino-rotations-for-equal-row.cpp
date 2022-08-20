class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int sol = INT_MAX;
        int n = tops.size();
        for(int k=1;k<7;k++) {
            int t = 0, b = 0;
            bool cons = true;
            for(int i=0;i<n;i++) {
                if (tops[i]!=k && bottoms[i]!=k) {
                    cons = false;
                    break;
                }
                t+=tops[i]!=k ? 1 : 0;
                b+=bottoms[i]!=k ? 1 : 0;
            }
            if (cons) {
                sol = min(t,b);
            }
        }
        return sol == INT_MAX ? -1 : sol;
    }
};
