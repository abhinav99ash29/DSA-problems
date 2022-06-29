class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>&a, vector<int>&b) {
            if (a[0]!=b[0]) return a[0]>b[0];
            else return a[1]<b[1];
        }); 
        vector<vector<int>> q;
        for(vector<int>& i: people) {
            q.insert(q.begin()+i[1],i);
        } 
        return q;
    }
};    
