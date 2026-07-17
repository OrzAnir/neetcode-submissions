class Solution {
public:
    void func(int n, string& ds, vector<string>& result, stack<char>& st) {
        if (ds.size() == 2*n) {
            if (st.size() == 0) result.push_back(ds);
            return;
        }
        ds.push_back('(');
        st.push('(');
        func(n, ds, result, st);
        ds.pop_back();
        st.pop();
        if (st.size() != 0) {
            ds.push_back(')');
            char c = st.top();
            st.pop();
            func(n, ds, result, st);
            ds.pop_back();
            st.push(c);
        }
    }
    vector<string> generateParenthesis(int n) {
        string ds;
        vector<string> result;
        stack<char> st;
        func(n, ds, result, st);
        return result;
    }
};
