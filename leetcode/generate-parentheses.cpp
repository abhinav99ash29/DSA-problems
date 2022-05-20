class Solution {
    vector<string> ans;
public:
    
    void fn(int op, int cl, string& temp, int n) {
        if (op==n&&cl==n) {
            ans.push_back(temp);
            return;
        }
        if (op<n) {
            temp.push_back('(');
            fn(op+1,cl,temp,n);
            temp.pop_back();
        }
        if (cl<op) {
            temp.push_back(')');
            fn(op,cl+1,temp,n);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string temp="";
        fn(0,0,temp,n);
        return ans;
    }
};
