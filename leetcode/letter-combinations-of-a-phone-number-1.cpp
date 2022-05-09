class Solution {
    vector<string> let;
public:
    vector<string> fn(string &digits, int idx) {
        if (idx>=digits.size()) return {""};
        
        vector<string> ans;
        for(int i=0;i<let[digits[idx]-'0'].size();i++) {
            string s = "";
            s += let[digits[idx]-'0'][i];
            vector<string> ans1 = fn(digits,idx+1);
            for(string s1: ans1) {
                string s2 = s;
                s2+=s1;
                ans.push_back(s2);
            }
        }
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        let = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        return fn(digits, 0);
    }
};
