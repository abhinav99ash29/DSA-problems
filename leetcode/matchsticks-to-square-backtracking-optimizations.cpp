class Solution {
public:
    
    bool dfs(int curr, vector<int>& sides, vector<int>& match, int target) {
        if (curr==match.size()) {
            return sides[0]==sides[1]&&sides[1]==sides[2]&&sides[2]==sides[3];
        }
        for(int i=0;i<4;i++) {
            if (sides[i]+match[curr]>target) continue;
            int j = i;
            while(--j>=0) {
                if (sides[j]==sides[i]) break;
            }
            if (j!=-1) continue;
            sides[i]+=match[curr];
            if (dfs(curr+1, sides, match, target))
                return true;
            sides[i]-=match[curr];
        }
        return false;
    }
    
    bool makesquare(vector<int>& match) {
        sort(match.begin(), match.end(), greater<int>());
        int sum = accumulate(match.begin(), match.end(),0);
        if (sum%4) return false;
        vector<int> sides(4,0);
        return dfs(0,sides,match,sum/4);
    }
};
