class Solution {
public:
    string convert(string s, int num) {
        if (num==1) return s;
        vector<string> v(num, "");
        int n = s.size();
        bool dir = false;
        int i = 0;
        for(char &c: s) {
            // cout<<i<<" "<<dir<<endl;
            v[i]+=c;
            if (i==0 || i==num-1) dir = !dir;
            i += dir ? 1 : -1;
        }
        string ans = "";
        for(string& str: v) ans+=str;
        return ans;
    }
};
