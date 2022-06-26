class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        int total = 0;
        int n = cardPoints.size();
        if (k==1) return max(cardPoints[0],cardPoints[n-1]);
        for(int& c: cardPoints) {
            total+=c;
        }
        int currsum = 0;
        int x = n-k;
        for(int i=0;i<x;i++) {
            currsum+=cardPoints[i];
        }
        int ans = total-currsum;
        for(int i=x;i<n;i++) {
            // cout<<currsum<<endl;
            currsum += cardPoints[i]-cardPoints[i-x];
            ans = max(ans, total-currsum);
        }
        return ans;
    }
};
