class Solution {
public:
    bool func(int index, string s, set<string>& st, vector<int>& dp) {
        int n = s.size();
        if (index >= n) return true;
        if (dp[index] != -1) return dp[index];
        for(int i = index; i < n; i++) {
            string str = s.substr(index, i - index + 1);
            if (st.find(str) != st.end()) {
                if (func(i + 1, s, st, dp)) return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        int n = s.size();
        for(string s1 : wordDict) st.insert(s1);
        vector<int> dp(n, -1);
        return func(0, s, st, dp);
    }
};
