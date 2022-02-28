class Solution {
public:
    unordered_map<string, vector<int>> m;
    vector<int> diffWaysToCompute(string exp) {
        
        if (m.find(exp)!=m.end()) return m[exp];
        
        vector<int> res;
        
        int size = exp.size();
        
        for(int i=0;i<size;i++) {
            char curr = exp[i];
            if (curr == '+' || curr == '-' || curr == '*') {
                string s1 = exp.substr(0,i);
                string s2 = exp.substr(i+1);
                vector<int> res1, res2;
                if (m.find(s1) != m.end()) res1 = m[s1];
                    else res1 = diffWaysToCompute(s1);
                if (m.find(s2) != m.end()) res2 = m[s2];
                    else res2 = diffWaysToCompute(s2);;
                    
                
                for(auto n1: res1) {
                    for (auto n2: res2) {
                        if (curr == '+') {
                            res.push_back(n1+n2);
                        } else if (curr == '-') {
                            res.push_back(n1-n2);
                        } else {
                            res.push_back(n1*n2);
                        }
                    }
                }
            }
        }
        
        if (res.size() == 0) {
            res.push_back(stoi(exp));
        }
        
        return m[exp] = res;
    }
};
