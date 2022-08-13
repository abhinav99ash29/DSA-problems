class Solution {
public:
    int dfs(int i, vector<int>& manager, vector<int>& time) {
        if (manager[i] != -1) {
            time[i]+=dfs(manager[i],manager,time);
            manager[i]=-1;
        }
        return time[i];
    }
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        for(int i=0;i<manager.size();i++) {
            res = max(res, dfs(i,manager,informTime));
        }
        return res;
    }
};
