class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        char prev=chars[0];
        int cnt = 0;
        string s = "";
        for(int i=0;i<n;i++) {
            if (chars[i] == prev) {
                cnt++;
            } else {
                s+=prev;
                if (cnt>1) {
                    s+=to_string(cnt);
                }
                cnt=1;
                prev = chars[i];
            }
        }
        s+=prev;
        if (cnt>1) s+=to_string(cnt);
        chars.clear();
        for(char&c: s) chars.push_back(c);
        return s.size();
    }
};
