class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(string s: tokens) {
            if (s=="+") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                st.push((long long)b+a);
            } else if (s=="-") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                st.push((long long)b-a);
            } else if (s=="*") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                st.push((long long)b*a);
            } else if (s=="/") {
                long long a = st.top(); st.pop();
                long long b = st.top(); st.pop();
                st.push(b/a);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
