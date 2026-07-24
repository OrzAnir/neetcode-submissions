class Solution {
public:
    int func(int index, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (index == n) return 0;
        if (dp[index][prev + 1] != -1) return dp[index][prev + 1];
        int take = -1e8, notTake;
        if (prev == -1 || nums[index] > nums[prev]) {
            take = 1 + func(index + 1, index, nums, dp);
        }
        notTake = func(index + 1, prev, nums, dp);
        return dp[index][prev + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return func(0, -1, nums, dp);
    }
};
