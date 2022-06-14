class Solution {
    vector<vector<int>> dp;
public:
    
    int fn(string& w1, string& w2, int i, int j) {
        if (i==w1.size() && j==w2.size()) return 0;
        if (i==w1.size() || j==w2.size()) return (w1.size()-i)+(w2.size()-j);
        if (dp[i][j]!=-1) return dp[i][j];
        if (w1[i] == w2[j]) return dp[i][j] = fn(w1,w2,i+1,j+1);
        return dp[i][j] = min(1+fn(w1,w2,i+1,j), 1+fn(w1,w2,i,j+1));
    }
    
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(), vector<int>(word2.size(),-1));
        return fn(word1, word2, 0, 0);
    }
};
