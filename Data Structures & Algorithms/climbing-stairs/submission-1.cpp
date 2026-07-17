class Solution {
public:
    int func(int val, vector<int>& dp) {
        if (val == 0) return 1;
        if (val < 0) return 0;
        if (dp[val] != -1) return dp[val];
        return dp[val] = func(val - 1, dp) + func(val - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return func(n, dp);
    }
};
