class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totgas=0, totcost = 0;
        int curr=0, start=0;
        for(int i=0;i<n;i++) {
            totgas+=gas[i];
            totcost+=cost[i];
            curr += gas[i]-cost[i];
            if (curr<0) {
                start = i+1;
                curr = 0;
            }
        }
        return totcost>totgas ? -1 : start;
    }
};
