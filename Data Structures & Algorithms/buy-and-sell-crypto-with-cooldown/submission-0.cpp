class Solution {
public:
    int func(int index, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if (index == n) {
            if (buy == 1) return -1e8;
            else return 0;
        }   
        if (dp[index][buy] != -1) return dp[index][buy];
        if (buy == 0) {
            int take = -prices[index] + func(index + 1, 1, prices, dp);
            int notTake = func(index + 1, 0, prices, dp);
            return dp[index][buy] = max(take, notTake);
        }
        else if (buy == 1) {
            int take = prices[index] + func(index + 1, 2, prices, dp);
            int notTake = func(index + 1, 1, prices, dp);
            return dp[index][buy] = max(take, notTake);
        }
        else if (buy == 2) {
            return dp[index][buy] = func(index + 1, 0, prices, dp);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return func(0, 0, prices, dp);
        // buy = 0 -> no one has bought
        // buy = 1 -> someone has bought but not sold
        // buy = 2 -> someone has sold, now cooldown
    }
};
