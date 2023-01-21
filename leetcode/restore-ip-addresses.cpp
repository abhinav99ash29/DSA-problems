class Solution {
public:
    string getStr(vector<string>& sol) {
        int i=0;
        string s="";
        for(;i<sol.size()-1;i++) {
            s+=sol[i];
            s+='.';
        }
        s+=sol[i];
        return s;
    }
    void fn(string s, int i, vector<string>& ans, vector<string>& sol) {
        if (sol.size()>4) return;
        if (i==s.size()) {
            if (sol.size()==4)
                ans.push_back(getStr(sol));
            else
                return;
        }
        int j = i;
        string c = "";
        while(j<s.size() && j<i+3) {
            if (j==i+1 && s[j-1]=='0') break;
            c += s[j];
            if (stoi(c)<=255) {
                sol.push_back(c);
                fn(s,j+1,ans,sol);
                sol.pop_back();
            } else {
                break;
            }
            j++;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 15) return {};
        vector<string> ans;
        vector<string> sol;
        fn(s,0,ans,sol);
        return ans;
    }
};
