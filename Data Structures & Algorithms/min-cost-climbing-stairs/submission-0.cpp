class Solution {
public:
    int func(int index, vector<int>& cost, vector<int>& dp) {
        if (index >= (int)cost.size()) return 0;
        if (index >= 0 && dp[index] != -1) return dp[index];
        int val = (index == -1) ? 0 : cost[index];
        int x = val + func(index + 1, cost, dp);
        int y = val + func(index + 2, cost, dp);
        if (index >= 0) dp[index] = min(x, y);
        return min(x, y);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return func(-1, cost, dp);
    }
};
