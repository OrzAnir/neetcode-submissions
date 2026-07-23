class Solution {
public:
    bool func(int index, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (index == n) {
            if (sum == 0) return true;
            return false;
        }
        if (sum == 0) return true;
        if (dp[index][sum] != -1) return dp[index][sum];
        if (sum - nums[index] >= 0) {
            if (func(index + 1, sum - nums[index], nums, dp)) return dp[index][sum] = true;
        } 
        if (func(index + 1, sum, nums, dp)) return dp[index][sum] = true;
        return dp[index][sum] = false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) sum += nums[i];
        if (sum % 2 != 0) return false;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return func(0, sum/2, nums, dp);
    }
};
