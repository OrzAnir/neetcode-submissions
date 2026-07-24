class Solution {
public:
    int func(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (index == 0) {
            if (amount % coins[index] == 0) return 1;
            else return 0;
        }
        if (amount == 0) return 1;
        if (dp[index][amount] != -1) return dp[index][amount];
        int take = 0, notTake = 0;
        if (amount - coins[index] >= 0) {
            take = func(index, amount - coins[index], coins, dp);
        }
        notTake = func(index - 1, amount, coins, dp);
        return dp[index][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return func(n - 1, amount, coins, dp);
    }
};
