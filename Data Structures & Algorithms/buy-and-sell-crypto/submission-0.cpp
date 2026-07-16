class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0, buy = prices[0];
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            if (prices[i] < buy) buy = prices[i];
            else {
                int profit = prices[i] - buy;
                maxprofit = max(maxprofit, profit);
            }
        }
        return maxprofit;
    }
};
