class Solution {
public:
    bool check(int& v, string& s) {
        for(int i=0;i<s.size();i++) {
            if (1<<(s[i]-'a') & v) return false;
            v = v | 1<<(s[i]-'a');
        }
        return true;
    }
    
    int fn(int i, int v, vector<string>& arr) {
        if (i>=arr.size()) return 0;
        int sol = 0;
        sol = fn(i+1,v,arr);
        int temp = v;
        if (check(temp,arr[i])) {
            sol = max(sol, (int)arr[i].size()+fn(i+1,temp,arr));
        }
        return sol;
    }
    
    int maxLength(vector<string>& arr) {
        int v = 0;
        return fn(0,v,arr);
    }
};
