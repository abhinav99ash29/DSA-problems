class Solution {
    vector<vector<char>> mp;
    vector<string> ans;
public:
    
    void fn(string& digits, int i, string& soFar) {
        // cout<<i<<" "<<soFar<<endl;
        if (i>digits.size()) return;
        if (i == digits.size()) {ans.push_back(soFar); return;}
        for(char c: mp[digits[i]-'2']) {
            soFar = soFar + c;
            fn(digits,i+1,soFar);
            soFar.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        mp = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m', 'n','o'},{'p','q','r', 's'},{'t','u','v'},{'w','x','y', 'z'}};
        string tmp = "";
        fn(digits, 0, tmp);
        return ans;
    }
};
