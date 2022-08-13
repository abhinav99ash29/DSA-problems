class Solution {
public:
    int dfs(map<int, vector<int>> &mp, vector<int>& time, int root, int currt) {
        int sol = 0;
        if (mp[root].size()==0) return currt;
        for(int i=0;i<mp[root].size();i++) {
            sol = max(sol, dfs(mp,time,mp[root][i],currt+time[root]));
        }
        return sol;
    }
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int, vector<int>> mp;
        for(int i=0;i<manager.size();i++) {
            if (manager[i]!=-1) {
                mp[manager[i]].push_back(i);
            }
        }
        return dfs(mp,informTime, headID, 0);
    }
};
