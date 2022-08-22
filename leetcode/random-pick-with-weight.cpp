class Solution {
    vector<int> pref;
    int sum;
public:
    Solution(vector<int>& w) {
        
        pref.resize(w.size(),0);
        pref[0] = w[0];
        sum = w[0];
        for(int i=1;i<w.size();i++) {
            pref[i] = w[i];
            sum+=w[i];
            pref[i]+=pref[i-1];
        }
    }
    
    int pickIndex() {
        int x = rand() % sum;
        auto it = upper_bound(pref.begin(), pref.end(), x);
        // cout<<x<<" "<<it - pref.begin()<<endl;
        return it - pref.begin();
    }
};
