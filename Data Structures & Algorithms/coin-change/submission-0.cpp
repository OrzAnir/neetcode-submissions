class Solution {
public:
    int func(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (index == 0) {
            if (amount % coins[index] == 0) return amount/coins[index];
            else return 1e8;
        }
        if (dp[index][amount] != -1) return dp[index][amount];
        int take = 1e8, notTake;
        if (amount - coins[index] >= 0) {
            take = 1 + func(index, amount - coins[index], coins, dp);
        }
        notTake = func(index - 1, amount, coins, dp);
        return dp[index][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(n - 1, amount, coins, dp);
        if (ans >= 1e8) return -1; 
        else return ans;
    }
};
