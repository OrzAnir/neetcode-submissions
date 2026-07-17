class Solution {
public:
    void func(int open, int close, int n, string& ds, vector<string>& result) {
        if (close > open) return;
        if (ds.size() == 2*n) {
            if (open == close) result.push_back(ds);
            return;
        }
        ds.push_back('(');
        func(open + 1, close, n, ds, result);
        ds.pop_back();
        ds.push_back(')');
        func(open, close + 1, n, ds, result);
        ds.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string ds;
        vector<string> result;
        func(0, 0, n, ds, result);
        return result;
    }
};
