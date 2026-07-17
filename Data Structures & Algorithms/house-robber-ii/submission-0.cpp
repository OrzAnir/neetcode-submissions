class Solution {
public:
    int func(int index, int val, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (val == 1 && index >= n - 1) return 0;
        else if (val == 0 && index >= n) return 0;
        if (dp[index][val] != -1) return dp[index][val];
        int take, notTake;
        if (index == 0) {
            take = nums[index] + func(index + 2, 1, nums, dp);
            notTake = func(index + 1, 0, nums, dp);
        }
        else {
            take = nums[index] + func(index + 2, val, nums, dp);
            notTake = func(index + 1, val, nums, dp);
        }
        return dp[index][val] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return func(0, 0, nums, dp);
    }
};
