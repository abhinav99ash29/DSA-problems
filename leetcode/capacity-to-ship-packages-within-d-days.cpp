class Solution {
public:
    bool check(vector<int>& wt, int cap, int days) {
        int n = wt.size();
        int i=0;
        while(days--) {
            int sum = 0;
            while(i<n && sum+wt[i] <= cap) {
                sum+=wt[i];
                i++;
            }
            if (i==n) return true;
        }
        return false;
    }

    int shipWithinDays(vector<int>& wt, int days) {
        int sum = 0;
        int mx = 0;
        for(int&i: wt) {
            mx = max(i, mx);
            sum+=i;
        }
        int l = mx, r = sum;
        while(l<=r) {
            int mid = (l+r)/2;
            if (check(wt,mid,days)) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};
