class Solution {
public:
    bool isValid(string& s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push('(');
            else {
                if (st.size() == 0) return false;
                st.pop();
            }
        }
        if (st.size() != 0) return false;
        return true;
    }
    void func(int n, string& ds, vector<string>& result) {
        if (ds.size() == 2*n) {
            if (isValid(ds)) result.push_back(ds);
            return;
        }
        ds.push_back('(');
        func(n, ds, result);
        ds.pop_back();
        ds.push_back(')');
        func(n, ds, result);
        ds.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string ds;
        vector<string> result;
        func(n, ds, result);
        return result;
    }
};
