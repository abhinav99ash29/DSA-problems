class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int sol = INT_MAX;
        int n = a.size();
        vector<int> ca(7,0), cb(7,0), same(7,0);
        for(int i=0;i<n;i++) {
            ca[a[i]]++;
            cb[b[i]]++;
            if (a[i] == b[i]) same[a[i]]++;
        }
        for(int i=1;i<=6;i++) {
            if (ca[i]+cb[i]-same[i] == n) return min(ca[i]-same[i], cb[i]-same[i]);
        }
        return -1;
    }
};
