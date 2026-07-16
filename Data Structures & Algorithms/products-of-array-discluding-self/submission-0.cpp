class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, numZeros = 0;
        int n = nums.size();
        for(int x : nums) {
            if (x == 0) {
                numZeros += 1;
                continue;
            }
            product *= x;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (numZeros > 1) ans.push_back(0);
                else ans.push_back(product);
            }
            else {
                if (numZeros >= 1) ans.push_back(0);
                else ans.push_back(product/nums[i]);
            }
        }
        return ans;
    }
};
