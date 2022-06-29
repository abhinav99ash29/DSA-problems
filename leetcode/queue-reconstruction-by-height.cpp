class Solution {
public:
    
    void assign(vector<vector<int>>& q, vector<int>& val) {
        int k = val[1];
        for(vector<int>& i: q) { // insert at the kth empty position
            if (i[0]==-1) {
                if (k==0) {
                    i = val;
                    return;
                }
                k--;
            }
        }
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>&a, vector<int>&b) {
            if (a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
        }); // sort with ascending heights and for same in descending position
        vector<vector<int>> q(people.size(), vector<int>(2,-1));
        for(vector<int>& i: people) {
            assign(q,i);
        } 
        return q;
    }
};
