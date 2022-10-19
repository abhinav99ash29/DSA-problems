class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for(string& w: words) {
            m[w]++;
        }
        vector<vector<string>> v(words.size()+1, vector<string>());
        for(auto& i: m) {
            v[i.second].push_back(i.first);
        }
        vector<string> sol;
        for(int i=words.size();i>=0;i--) {
            vector<string> temp;
            for(int j=0;j<v[i].size()&&k>0;j++) {
                temp.push_back(v[i][j]);
                k--;
            }
            sort(temp.begin(), temp.end());
            for(int j=0;j<temp.size();j++) sol.push_back(temp[j]);
            if (!k) break;
        }
        return sol;
    }
};
