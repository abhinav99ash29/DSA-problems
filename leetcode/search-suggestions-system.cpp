class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> sol;
        string s = "";
        int idx = -1;
        for(int i=0;i<searchWord.size();i++) {
            s+=searchWord[i];
            sol.push_back({});
            idx++;
            auto lb = lower_bound(products.begin(), products.end(), s);
            int j = 3;
            for(;lb!=products.end() && !(*lb).compare(0,s.size(),s) && j>0;lb++,j--) {
                sol[idx].push_back(*lb);
            }
        }
        return sol;
    }
};
