class Solution {
public:
    int func(int index, string s, vector<int>& dp) {
        int n = s.size();
        if (index < n && s[index] == '0') return 0;
        if (index >= n - 1) return 1;
        if (dp[index] != -1) return dp[index];
        int ways = 0;
        ways += func(index + 1, s, dp);
        if (stoi(s.substr(index, 2)) <= 26) ways += func(index + 2, s, dp);
        return dp[index] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return func(0, s, dp);
    }
};
