class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 1;
        vector<int> hash(n, -1);
        for(int i = 0; i < n; i++) hash[i] = i;
        for(int i = 1; i < n; i++) {
            int maxdp = 0, maxInd = i;
            for(int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] > maxdp) {
                    maxdp = dp[j];
                    maxInd = j;
                }
            }
            dp[i] = maxdp + 1;
            hash[i] = maxInd;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
