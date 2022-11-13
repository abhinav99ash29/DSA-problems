class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string w = "";
        int n = s.size();
        for(int i=0;i<n;i++) {
            if (s[i]==' ') {
                if (w!="") {
                    st.push(w);
                }
                w = "";
                continue;
            }
            w+=s[i];
        }
        if (w!="") st.push(w);
        string str = "";
        while(st.size()) {
            str+=st.top() + " ";
            st.pop();
        }
        str.pop_back();
        return str;
    }
};
