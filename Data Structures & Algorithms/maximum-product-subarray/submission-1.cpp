class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, curMin = 1, curMax = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int temp = nums[i] * curMax;
            curMax = max(nums[i], max(nums[i] * curMax, nums[i] * curMin));
            curMin = min(nums[i], min(temp, nums[i] * curMin));
            res = max(res, curMax);
        }
        return res;
    }
};
