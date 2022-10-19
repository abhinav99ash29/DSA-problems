class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for(string& w: words) {
            m[w]++;
        }
        vector<pair<int, string>> v;
        for(auto& i: m) {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), [](pair<int,string>&a, pair<int,string>&b) {
           if (a.first!=b.first) return a.first>b.first;
           return a.second<b.second; 
        });
        vector<string> sol;
        int i=0;
        for(pair<int, string>& p: v) {
            if (i<k) {
                sol.push_back(p.second);
                i++;
            } else {
                break;
            }
            
        }
        return sol;
    }
};
