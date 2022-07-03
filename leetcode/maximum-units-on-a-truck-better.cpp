class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) { // storing boxes with certain units in an array instead of sorting the original
        vector<int> type(1001, 0);
        for(vector<int>& i: boxTypes) {
            type[i[1]] += i[0];
        }
        int ans = 0;
        for(int i=1000;i>=1;i--) {
            if (truckSize>=type[i]) {
                truckSize-=type[i];
                ans+=type[i]*i;
            } else if (truckSize>0) {
                ans+=truckSize*i;
                truckSize=0;
                break;
            } else {
                break;
            }
        }
        return ans;
    }
};
