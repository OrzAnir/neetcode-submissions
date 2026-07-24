class Solution {
public:
    int func(int index, int target, int offset, vector<int>& nums, vector<vector<int>>& dp) {
        int ways = 0;
        if (index == 0) {
            if (target - nums[index] == 0) ways += 1;
            if (target + nums[index] == 0) ways += 1;
            return ways;
        }
        if (dp[index][target + offset] != -1) return dp[index][target + offset];
        ways += func(index - 1, target - nums[index], offset, nums, dp);
        ways += func(index - 1, target + nums[index], offset, nums, dp);
        return dp[index][target + offset] = ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;
        if (target > sum) return 0;
        int offset = sum - target;
        vector<vector<int>> dp(n, vector<int>(target + sum + offset + 1, -1));
        return func(n - 1, target, offset, nums, dp);
    }
};
